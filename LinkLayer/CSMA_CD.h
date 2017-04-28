#pragma once
class CCSMA_CD
{
public:
	CCSMA_CD();
	~CCSMA_CD();

	void monitor(); // ¼àÌý

	bool send();	// ·¢ËÍ

	bool detect();	// ¼ì²â

	void handle();	// ³åÍ»´¦Àí
};

