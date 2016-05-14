#ifndef SSF_CORE_COMMAND_LINE_STANDARD_COMMAND_LINE_H
#define SSF_CORE_COMMAND_LINE_STANDARD_COMMAND_LINE_H

#include <cstdint>

#include <string>
#include <stdexcept>
#include <vector>
#include <regex>
#include <memory>

#include <boost/program_options.hpp>
#include <boost/system/error_code.hpp>

namespace ssf {
namespace command_line {
namespace standard {

class CommandLine {
 public:
  using ParsedParameters = std::map<std::string, std::vector<std::string>>;

 public:
  CommandLine(bool is_server = false);

  ParsedParameters parse(int argc, char* argv[], boost::system::error_code& ec);

  ParsedParameters parse(
      int ac, char* av[],
      const boost::program_options::options_description& services,
      boost::system::error_code& ec);

  uint16_t port();

  std::string addr();

  std::string circuit_file();

  std::string config_file();

  bool IsPortSet();

  bool IsAddrSet();

 private:
  ParsedParameters InternalParsing(
      const boost::program_options::variables_map& vm,
      boost::system::error_code& ec);

  uint16_t port_;
  std::string addr_;
  std::string circuit_file_;
  std::string config_file_;
  bool addr_set_;
  bool port_set_;
  bool is_server_;
};

}  // standard
}  // command_line
}  // ssf

#endif  // SSF_CORE_COMMAND_LINE_STANDARD_COMMAND_LINE_H
