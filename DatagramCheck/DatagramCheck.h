#pragma once
#ifdef DATAGRAMCHECK_EXPORTS
#define DATAGRAMCHECK_API __declspec(dllexport)
#else
#define DATAGRAMCHECK_API __declspec(dllimport)
#endif

// This class is exported from the DatagramCheck.dll
class DATAGRAMCHECK_API CDatagramCheck {
public:
	CDatagramCheck(void);
	// TODO: add your methods here.
	void setPara(char *pHead, int ilength);
	int check(int proto);
	enum CHCK_METHOD
	{
		CRC  = 1,
	};
protected:
	int CRCcheck();
private:
	char	*m_pMsgHead;
	int		m_iMsgLen;
};
