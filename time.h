class Time {
public:
	Time();
	Time(double quantum);
	~Time();

	void setTimeQuantum(double quantum);
	void increaseQuantum(double value); // Speed down.
	void decreaseQuantum(double value); // Speed up.
	void resetQuantum();
	void stopTime();
	void resumeTime();

	double getBasicQuantum();
	double getCurrentQuantum();

	bool isStop;

private:
	double currentQuantum;
	double basicQuantum;

	const double defaultQuantum = 1.0;
};
