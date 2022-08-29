#include <string>
#include <vector>

#include "tranceiver.h"


typedef enum { beacon_mode_ax25, beacon_mode_aprs } beacon_mode_t;

class tranceiver_beacon : public tranceiver
{
private:
	const std::string   beacon_text;
	const int           beacon_interval { 300              };
	const beacon_mode_t bm              { beacon_mode_aprs };
	const std::string   callsign        { "mycallsign"     };

protected:
	transmit_error_t put_message_low(const uint8_t *const p, const size_t s) override;

public:
	tranceiver_beacon(const std::string & id, seen *const s, work_queue_t *const w, const std::string & beacon_text, const int beacon_interval, const beacon_mode_t bm, const std::string & callsign);
	virtual ~tranceiver_beacon();

	static tranceiver *instantiate(const libconfig::Setting & node, work_queue_t *const w);

	void operator()() override;
};