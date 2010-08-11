#include "Connection.h"
#include "Message.h"

#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

using namespace std;

static double seconds() {
  struct timeval now;
  if (gettimeofday(&now, 0L)) {
    perror("seconds");
    exit(1);
    return 0;
  } else
    return (double)((double)now.tv_sec + ((double)now.tv_usec / 1000000.0));
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <LogFilename>" << endl;
    return -1;
  }
  Connection com;
  com.open();
  while (1) {
    const Message *result = com.readMessage();
    ofstream logFile(argv[1], ios_base::app);
    logFile << seconds() << " ";
    logFile << *result;
    logFile.close();
    delete result;
  }
  com.close();
  return 0;
}
