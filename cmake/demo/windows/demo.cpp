


#include "client/windows/handler/exception_handler.h"

static bool DumpCallback(const wchar_t* dump_path,
                         const wchar_t* minidump_id,
                         void* context,
                         EXCEPTION_POINTERS* exinfo,
                         MDRawAssertionInfo* assertion,
                         bool succeeded) {
  printf("Dump path: %ls\n", dump_path);
  return succeeded;
}

int add(int a, int b) {
  printf("a: %d, b: %d\n", a, b);
  int c = a + b / 0;
  printf("%d", c);
  return c;
}

int main(char* argv[], int argc) {
  std::wstring dump_path = L"./";
  static google_breakpad::ExceptionHandler handler(
      dump_path, nullptr, DumpCallback, nullptr,
      google_breakpad::ExceptionHandler::HANDLER_ALL);

  printf("Hello, world!\n");
  printf("%d", add(1, 0));
  int* p = nullptr;
  *p = 0;
  return 0;
}