#include <string>
int a;
#include <bits/stdc++.h>
#include <regex>
#include <iostream>
#include <string>
using namespace std;
std::string list123;
std::string cur_string;
size_t num = 0;
#include "/home/maxlun/Documents/Parcing/Generator/expr/lexer.h"
void scan_string(const std::string& m_tmp_variable){
  list123 = m_tmp_variable;
}
std::string getStr(){
  return cur_string;
}
Token getToken(){
begin:
if (list123.empty()){  return GENERATOR_END;}  {
  std::regex regexp( R"(^[ \n\t]+)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      list123 = match.suffix();
goto begin;}
}
}  {
  std::regex regexp( R"(^[0-9]+)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
a = std::stoi(cur_string);
return NUMBER;}
}
}  {
  std::regex regexp( R"(^\+)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return ADD;}
}
}  {
  std::regex regexp( R"(^\/)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return DIV;}
}
}  {
  std::regex regexp( R"(^\*\*)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return POW;}
}
}  {
  std::regex regexp( R"(^\*)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return MUL;}
}
}  {
  std::regex regexp( R"(^\-)");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return SUB;}
}
}  {
  std::regex regexp( R"(^\()");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return LB;}
}
}  {
  std::regex regexp( R"(^\))");
  std::smatch match;if (std::regex_search(list123,match, regexp)){
  if (!match.empty()){
      cur_string = match.str();
      list123 = match.suffix();
return RB;}
}
}throw std::runtime_error(std::string("no such token for ").append(list123));}
