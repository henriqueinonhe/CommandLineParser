#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <QVector>
#include <QString>

using namespace std;

class CommandLineParser final
{
public:
    CommandLineParser();
    CommandLineParser(const QString &string);
    void parse(const QString &command);

    QString getMainCommand() const;
    QStringList getOptions() const;
    QStringList getPositionalArgs() const;

private:
    void cleanup();

    bool isSpace(const QChar &character) const;
    bool isQuotationMark(const QChar &character) const;
    bool isOptionCommand(const QString &command) const;
    bool isDoubleDash(const QString &command) const;

    //Parse Subroutines
    void removeTrailingSpaces(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar) const;
    void splitByWhitespace(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar, QString &splitCommands) const;
    void splitByQuotationMark(QString::ConstIterator &currentChar, const QString::ConstIterator &lastChar, QString &splitCommands) const;
    void splitCommands(QStringList &splitCommandsList, const QString &command) const;
    void parseOption(const QString &currentCommand);
    void classifyCommands(const QStringList &splitCommandsList);

    QString mainCommand;
    QStringList options;
    QStringList positionalArgs;
};

#endif // COMMANDLINEPARSER_H
