#pragma once
class CCSMA_CD
{
public:
	CCSMA_CD();
	~CCSMA_CD();

	void monitor(); // ����

	bool send();	// ����

	bool detect();	// ���

	void handle();	// ��ͻ����
};

