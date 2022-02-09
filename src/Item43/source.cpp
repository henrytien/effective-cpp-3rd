#include<iostream>
class CompanyA {
public:
	void SendCleartext(const std::string& msg);
	void SendEncrypted(const std::string& msg);
};

void CompanyA::SendCleartext(const std::string& msg) {
	std::cout << "Call CompanyA::SendCleartext() " << msg << '\n';
}

void CompanyA::SendEncrypted(const std::string& msg) {
	std::cout << "Call CompanyA::SendEncrypted() " << msg << '\n';
}

class CompanyB {
public:
	void SendCleartext(const std::string& msg);
	void SendEncrypted(const std::string& msg);
};

void CompanyB::SendCleartext(const std::string& msg) {
	std::cout << "Call CompanyB::SendCleartext() " << msg << '\n';
}

void CompanyB::SendEncrypted(const std::string& msg) {
	std::cout << "Call CompanyB::SendEncrypted() " << msg << '\n';
}

// class for holding information
// used to create a message
class MsgInfo {
public:
	MsgInfo(const std::string& company_name, const std::string& message, const std::string& time) :company_name_(company_name),
		message_(message), time_(time) {}
	~MsgInfo() {};

	inline std::string get_comany_name() const { return company_name_; }
	inline std::string get_message() const { return message_; }
	inline std::string get_time() const { return time_; }

private:
	std::string company_name_;
	std::string message_;
	std::string time_;
};
class CompanyZ { // this class offers no
public: // sendCleartext function
	void SendEncrypted(const std::string& msg);
};

void CompanyZ::SendEncrypted(const std::string& msg) {
	std::cout << "Call CompanyZ::SendEncrypted() " << msg << '\n';
}
template<typename Company>
class MsgSender {
public:
	MsgSender() {}
	~MsgSender() {}
	void SendClear(const MsgInfo& info);
	void SendSecret(const MsgInfo& info); // similar to sendClear, except calls c.sendEncrypted
};

template<typename Company>
void MsgSender<Company>::SendClear(const MsgInfo& info) {

	std::string msg = info.get_comany_name() + " " + info.get_message() + " " + info.get_time();
	Company c;
	c.SendCleartext(msg);
}

template<typename Company>
void MsgSender<Company>::SendSecret(const MsgInfo& info) {
	std::cout << "MsgSender<Company>::SendSecret " << info.get_message() << '\n';
}

template<>
class MsgSender<CompanyZ> {
public: // general template, except sendClear is omitted
	void SendSecret(const MsgInfo& info);
};

void MsgSender<CompanyZ>::SendSecret(const MsgInfo& info) {
	std::cout << "MsgSender<CompanyZ>::SendSecret " << info.get_message() << '\n';
}


template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
	LoggingMsgSender() {}
	~LoggingMsgSender() {}
	//using MsgSender<Company>::SendClear;
	void SendClearMsg(const MsgInfo& info);
};

template<typename Company>
void LoggingMsgSender<Company>::SendClearMsg(const MsgInfo& info) {
	//write "before sending" info to the log;
	this->SendClear(info); // call base class function;
	//SendClear(info); // call base class function;
	//MsgSender<Company>::SendClear(info); // call base class function;
	//write "after sending" info to the log;
}


int main() {
	std::cout << "Item 43: Know how to access names in templatized base classes.\n";

	LoggingMsgSender<CompanyB> log;
	MsgInfo info("Google", "Give you a offer!", "Henry");
	log.SendClearMsg(info);

	return 0;
}