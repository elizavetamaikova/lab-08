// Copyright 2021 elizavetamaikova

#include "Client.hpp"

Client::Client(std::string address, std::string port)
    : _address(address), _port(port)
{}

std::string Client::SendRequest(std::string target, std::string id)
{
  net::io_context ioc;

  tcp::resolver resolver(ioc);
  beast::tcp_stream stream(ioc);

  auto const results = resolver.resolve(_address, _port);

  stream.connect(results);

  int version = 11;
  http::request<http::string_body> req{http::verb::post, target, version};
  req.set(http::field::host, _address);
  req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
  req.set(beast::http::field::content_type, "text/plain");
  req.body() = FillBody(id);
  req.prepare_payload();

  http::write(stream, req);

  beast::flat_buffer buffer;

  http::response<http::dynamic_body> res;
  http::read(stream, buffer, res);

  beast::error_code ec;
  stream.socket().shutdown(tcp::socket::shutdown_both, ec);

  if (ec && ec != beast::errc::not_connected)
    throw beast::system_error{ec};
  return boost::beast::buffers_to_string(res.body().data());
}

std::string Client::FillBody(std::string id)
{
  return "input:" + id;
}
