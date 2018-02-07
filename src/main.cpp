#include <alica_ros_proxy/AlicaEngineInfo.h>
#include <ros/ros.h>

#include <cstdio>
#include <chrono>
#include <cassert>
#include <map>

using alica_ros_proxy::AlicaEngineInfo;
using alica_ros_proxy::AlicaEngineInfoConstPtr;

std::map<int32_t, AlicaEngineInfo> last_msgs;

size_t write_date_time(char* buff, size_t buff_size)
{
	using std::chrono::system_clock;
	using std::chrono::duration_cast;
	using std::chrono::milliseconds;
	auto now = system_clock::now();
	long long ms_since_epoch = duration_cast<milliseconds>(now.time_since_epoch()).count();
	time_t sec_since_epoch = time_t(ms_since_epoch / 1000);
	tm time_info;
	localtime_r(&sec_since_epoch, &time_info);
	return snprintf(buff, buff_size, "(%02d.%02d.%04d %02d:%02d:%02d.%03lld)",
		time_info.tm_mday, 1 + time_info.tm_mon, 1900 + time_info.tm_year,
		time_info.tm_hour, time_info.tm_min, time_info.tm_sec, ms_since_epoch % 1000);
}

void log_msg(int32_t id, const char* format, ...) {
	constexpr size_t buflen = 255;
	char output[buflen];
	size_t buf_index = 0;
	int printed;
	va_list args;

	printed = write_date_time(&output[buf_index], buflen-buf_index);
	assert(printed > 0);
	buf_index += printed;

	printed = snprintf(&output[buf_index], buflen-buf_index, " [%d] ", id);
	assert(printed > 0);
	buf_index += printed;

	va_start(args, format);
	printed = vsnprintf(&output[buf_index], buflen-buf_index, format, args);
	assert(printed > 0);
	buf_index += printed;
	va_end(args);

	puts(output);
}

void info_received(const AlicaEngineInfoConstPtr& msg) {
	const auto id = msg->senderID;

	// Check if we remember a last message
	const auto last = last_msgs.find(id);
	if (last == last_msgs.end()) {
		log_msg(id, "Received first Info");
		last_msgs.insert({id, *msg});
		return;
	}

	const auto last_msg = last->second;
	// Check if anything changed
	//log_msg(id, "Looking for changes...");
	if (last_msg.masterPlan != msg->masterPlan) {
		log_msg(id, "Masterplan: %s -> %s",
			last_msg.masterPlan.c_str(),
			msg->masterPlan.c_str());
	}

	if (last_msg.currentPlan != msg->currentPlan) {
		log_msg(id, "Plan: %s -> %s",
			last_msg.currentPlan.c_str(),
			msg->currentPlan.c_str());
	}

	if (last_msg.currentState != msg->currentState) {
		log_msg(id, "State: %s -> %s",
			last_msg.currentState.c_str(),
			msg->currentState.c_str());
	}

	if (last_msg.currentTask != msg->currentTask) {
		log_msg(id, "Task: %s -> %s",
			last_msg.currentTask.c_str(),
			msg->currentTask.c_str());
	}

	// update map
	last_msgs[id] = *msg;
}

int main(int argc, char *argv[]) {
	ros::init(argc, argv, "alica_log");
	ros::NodeHandle nh;

	// Subscribe to /AlicaEngine/AlicaEngineInfo
	ros::Subscriber alica_sub = nh.subscribe("/AlicaEngine/AlicaEngineInfo",
		       	1000, info_received);
	ros::spin();
	return 0;
}
