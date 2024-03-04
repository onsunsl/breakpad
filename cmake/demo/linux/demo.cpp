#include "client/linux/handler/exception_handler.h"


bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                         void* context,
                         bool succeeded) {
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}

int add(int a, int b) {
  printf("a: %d, b: %d\n", a, b);
  int c = a + b / 0;
  printf("%d", c);
  return c;
}

int main(int argc, char* argv[]) {
  google_breakpad::MinidumpDescriptor descriptor("/tmp/dump");
  google_breakpad::ExceptionHandler handler(descriptor, NULL, dumpCallback, NULL,true, -1);

  printf("Hello, world!\n");
  printf("%d", add(1, 0));
  int* p = nullptr;
  *p = 0;
  return 0;
}