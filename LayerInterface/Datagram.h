#pragma once
//====================================================================================
// Name        : Datagram
// Author      : XF_Shaw
// Version     : 2016/7/18
// Copyright   : 
// Description : 用来存储和修改报文段/数据包/帧信息的类
// Attantion   : 在协议栈的中间层，我们已经提供了数据内存的转储与释放功能。但当你编写
//				 数据链路层或应用层时，你应该注意是否需要回收内存垃圾。
//====================================================================================

/**
 * @author：Xiong_Joe
 * @date：2017/5/1
 * @brief: 这个类是数据报类，用来存储和转发数据，一方面要对上层的数据包进行包装，加入头部；
 * 另一方面，要对下层的数据包进行拆包，将包头信息去除，得到数据
 * @attention: 此处只对协议栈的中间层提供了数据内存的转储和释放功能，但当编写数据链路层或
 * 应用层时，应该注意是够需要回收内存垃圾
 */

class Datagram
{
public:
	char *pHead;			/**< 报文头指针*/
	char *pData;			/**< 报文数据指针*/
	char *pTail;			/**< 报文尾指针*/
	int m_nMegLen;			/**< 报文总长度*/
	int m_nMsgHeadLen;		/**< 报文头长度*/
	int m_nMsgTailLen;		/**< 报文尾长度*/

	Datagram() : Datagram(-1){ }

	/**
	* @brief	数据报的构造函数
	* @param[in] iMsgLen	数据报长度
	*/
	Datagram(int iMsgLen) {
		pHead = nullptr;
		pData = nullptr;
		pTail = nullptr;
		m_nMegLen = iMsgLen;
		//pHead = new char[m_nMegLen];
	}

	/**
	* @brief	数据报的拷贝
	* @param[in] pData	数据报头指针
	*/
	void cpyData(char *pData);

	/**
	* @brief	数据报的去头去尾操作
	* @attention	注意此处只是修改标记信息，并未进行内存的迁移与释放操作
	*/
	void rmvHeadBuf();

	/**
	* @brief	数据报的创建操作
	* @param[in] datagram	上层数据报
	*/
	void createBuf(Datagram datagram);

	/**
	* @brief	数据报的释放
	*/
	void release();

	int getId();
	void setId(int id);
private:
	int id;
};