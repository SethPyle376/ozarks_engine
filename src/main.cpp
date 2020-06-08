//
// Created by seth on 6/7/20.
//

#include <iostream>
#include <vector>

#include "bitsery/bitsery.h"
#include "bitsery/adapter/buffer.h"
#include "bitsery/traits/vector.h"
#include "bitsery/traits/string.h"

#include "util/Types.h"

using Buffer = std::vector<uint8_t>;
using OutputAdapter = bitsery::OutputBufferAdapter<Buffer>;
using InputAdapter = bitsery::InputBufferAdapter<Buffer>;

struct MyStruct
{
  uint32_t i;
  char str[6];
  std::vector<float> fs;
};

template <typename S>
void serialize(S& s, MyStruct& o)
{
  s.value4b(o.i);
  s.text1b(o.str);
  s.container4b(o.fs, 100);
}

int main()
{
  MyStruct data{8491, "hello", {15.0f, -8.5f, 0.045f}};
  MyStruct res{};

  Buffer buffer;
  auto writtenSize = bitsery::quickSerialization(OutputAdapter{buffer}, data);
  auto state = bitsery::quickDeserialization(InputAdapter{buffer.begin(), writtenSize}, res);

  assert(state.first == bitsery::ReaderError::NoError && state.second);
  assert(data.fs == res.fs && data.i == res.i && std::strcmp(data.str, res.str) == 0);
}