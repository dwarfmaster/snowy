
#ifndef DEF_DATE
#define DEF_DATE

class Date
{
	public:
		Date();
		~Date();

		unsigned short addM();
		unsigned short subM();
		unsigned short addH();
		unsigned short subH();

		unsigned short getH() const;
		unsigned short getM() const;
		unsigned short getS() const;

		void update();
		bool operator==(const Date& d) const;

	private:
		unsigned short m_houre;
		unsigned short m_min;
		unsigned short m_sec;
		long m_lastTime;
};

#endif
