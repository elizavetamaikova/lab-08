#include <Client.hpp>

int main()
{
  Client a("127.0.0.1", "8080");
  std::cout << a.SendRequest("/v1/api/suggest", "hel") << std::endl;
}