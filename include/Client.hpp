// Copyright 2021 elizavetamaikova

#include <string>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

#ifndef TEMPLATE_CLIENT_HPP
#define TEMPLATE_CLIENT_HPP

class Client
{
 public:
  Client(std::string address, std::string port);
  std::string SendRequest(std::string target, std::string id);
  std::string FillBody(std::string id);
 private:
  std::string _address;
  std::string _port;
};

#endif  // TEMPLATE_CLIENT_HPP
