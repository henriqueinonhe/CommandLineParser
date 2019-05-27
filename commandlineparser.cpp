#include "commandlineparser.h"
#include <stdexcept>

CommandLineParser::CommandLineParser()
{

}

CommandLineParser::CommandLineParser(const QString &string)
{
    parse(string);
}

void CommandLineParser::parse(const QString &command)
{
    cleanup();
    QStringList splitCommandsList;
    splitCommands(splitCommandsList, command);
    classifyCommands(splitCommandsList);
}

void CommandLineParser::parse(const string &command)
{
    parse(QString(command.data()));
}

bool CommandLineParser::isSpace(const QChar &character) const
{
    return character == ' ';
}

bool CommandLineParser::isQuotationMark(const QChar &character) const
{
    return character == '\"';
}

bool CommandLineParser::isOptionCommand(const QString &command) const
{
    return command[0] == '-' &&
           command.size() >= 2 &&
           command != "--";
}

bool CommandLineParser::isDoubleDash(const QString &command) const
{
    return command == "--";
}

void CommandLineParser::removeTrailingSpaces(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar) const
{
    while(isSpace(*currentChar) && currentChar != lastChar)
    {
        currentChar++;
    }
}

void CommandLineParser::splitByWhitespace(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar, QString &splitCommand) const
{
    while(!isSpace(*currentChar) && currentChar != lastChar)
    {
        splitCommand.push_back(*currentChar);
        currentChar++;
    }
}

void CommandLineParser::splitByQuotationMark(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar, QString &splitCommand) const
{
    currentChar++;
    while(!isQuotationMark(*currentChar))
    {
        if(currentChar == lastChar)
        {
            throw invalid_argument("There are unpaired quotation marks!");
        }
        splitCommand.push_back(*currentChar);
        currentChar++;
    }
    currentChar++;
}

void CommandLineParser::splitCommands(QStringList &splitCommandsList, const QString &command) const
{
    QString::ConstIterator currentChar = command.begin();
    const QString::ConstIterator lastChar = command.end();
    while(currentChar != lastChar)
    {
        QString splitCommand;

        removeTrailingSpaces(currentChar, lastChar);
        if(!isQuotationMark(*currentChar))
        {
            splitByWhitespace(currentChar, lastChar, splitCommand);
        }
        else
        {
            splitByQuotationMark(currentChar, lastChar, splitCommand);
        }

        if(!splitCommand.isEmpty())
        {
            splitCommandsList.push_back(splitCommand);
        }
    }
}

void CommandLineParser::parseOption(const QString &currentCommand)
{
    if(currentCommand[1] == "-")
    {
        const int doubleDashCompensation = 2;
        const QString commandWithoutDoubleDash = currentCommand.mid(doubleDashCompensation);
        options.push_back(commandWithoutDoubleDash);
    }
    else
    {
        const int singleDashCompensation = 1;
        for(auto currentChar = currentCommand.begin() + singleDashCompensation; currentChar != currentCommand.end(); currentChar++)
        {
            options.push_back(*currentChar);
        }
    }
}

void CommandLineParser::classifyCommands(const QStringList &splitCommandsList)
{
    if(!splitCommandsList.isEmpty())
    {
        mainCommand = splitCommandsList[0];
        auto currentCommand = splitCommandsList.begin() + 1;
        auto lastCommand = splitCommandsList.end();
        while(currentCommand != lastCommand)
        {
            if(isOptionCommand(*currentCommand))
            {
                parseOption(*currentCommand);
            }
            else if(isDoubleDash(*currentCommand))
            {
                currentCommand++;
                while(currentCommand != lastCommand)
                {
                    positionalArgs.push_back(*currentCommand);
                    currentCommand++;
                }
                return;
            }
            else
            {
                positionalArgs.push_back(*currentCommand);
            }
            currentCommand++;
        }
    }
}

QStringList CommandLineParser::getPositionalArgs() const
{
    return positionalArgs;
}

void CommandLineParser::cleanup()
{
    options = QStringList();
    positionalArgs = QStringList();
}

QStringList CommandLineParser::getOptions() const
{
    return options;
}

QString CommandLineParser::getMainCommand() const
{
    return mainCommand;
}
