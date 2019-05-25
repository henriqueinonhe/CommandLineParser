//#include "catch.hpp"
//#include "commandlineparser.h"


//TEST_CASE("Command Line Parser")
//{
//    CommandLineParser parser;

//    parser.parse("");
//    CHECK(parser.getMainCommand() == "");
//    CHECK(parser.getOptions().isEmpty());
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse(" ");
//    CHECK(parser.getMainCommand() == "");
//    CHECK(parser.getOptions().isEmpty());
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse("list");
//    CHECK(parser.getMainCommand() == "list");
//    CHECK(parser.getOptions().isEmpty());
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse("arg1 arg2 arg3");
//    CHECK(parser.getMainCommand() == "arg1");
//    CHECK(parser.getOptions().isEmpty());
//    CHECK(parser.getPositionalArgs()[0] == "arg2");
//    CHECK(parser.getPositionalArgs()[1] == "arg3");

//    parser.parse("-a -b -c -d");
//    CHECK(parser.getMainCommand() == "-a");
//    CHECK(parser.getOptions()[0] == "b");
//    CHECK(parser.getOptions()[1] == "c");
//    CHECK(parser.getOptions()[2] == "d");
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse("comm --jagger --negger --freuder");
//    CHECK(parser.getMainCommand() == "comm");
//    CHECK(parser.getOptions()[0] == "jagger");
//    CHECK(parser.getOptions()[1] == "negger");
//    CHECK(parser.getOptions()[2] == "freuder");
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse("    list -h -abcd   ");
//    CHECK(parser.getOptions()[0] == "h");
//    CHECK(parser.getOptions()[1] == "a");
//    CHECK(parser.getOptions()[2] == "b");
//    CHECK(parser.getOptions()[3] == "c");
//    CHECK(parser.getOptions()[4] == "d");
//    CHECK(parser.getPositionalArgs().isEmpty());

//    parser.parse("list -d \"Lorem Ipsum\"");
//    CHECK(parser.getOptions()[0] == "d");
//    CHECK(parser.getPositionalArgs()[0] == "Lorem Ipsum");

//    CHECK_THROWS(parser.parse("aksndkasnd \""));
//    CHECK_THROWS(parser.parse("aksndkasnd \" \" \""));

//    parser.parse("list -d -- Neggets Fronks -s -v");
//    CHECK(parser.getOptions()[0] == "d");
//    CHECK(parser.getPositionalArgs()[0] == "Neggets");
//    CHECK(parser.getPositionalArgs()[1] == "Fronks");
//    CHECK(parser.getPositionalArgs()[2] == "-s");
//    CHECK(parser.getPositionalArgs()[3] == "-v");
//}
