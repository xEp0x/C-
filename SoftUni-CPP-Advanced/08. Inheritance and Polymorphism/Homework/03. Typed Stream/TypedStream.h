#ifndef CPP_ADVANCED_TYPEDSTREAM_H
#define CPP_ADVANCED_TYPEDSTREAM_H

#include <sstream>
#include <vector>

template<typename T>
class TypedStream {
private:
  explicit operator bool() const {
    return this->stream.good();
  }

protected:
  std::istringstream stream;

  explicit TypedStream(const std::string& input) : stream(input) { }

  virtual TypedStream<T>& operator>>(T& t) = 0;

public:
  virtual ~TypedStream() = default;

  std::vector<T> readToEnd() {
    std::vector<T> elements;
    T element;
    while (*this >> element) { // == this->operator>>(element).stream.good() == (*this >> element).stream.good()
      elements.push_back(element);
    }
    return elements;
  }
};

#endif //CPP_ADVANCED_TYPEDSTREAM_H
