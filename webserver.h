#include <string>

#include "stats.h"

void start_webserver(const int listen_port, const int ws_port_in, stats *const s);
void stop_webserver();