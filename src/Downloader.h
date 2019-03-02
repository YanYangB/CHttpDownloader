/*
 * ----------------------------------------------------
 * Copyright (c) 2019, Yan Yang. All Rights Reserved.
 * ----------------------------------------------------
 */
#pragma once
#include <iostream>
#include <curl/curl.h>
using namespace std;

class HttpDownloader {
public:
	HttpDownloader(const char url[], const char file[]);           //���캯��
	bool supportResumeDownload();     //���������Ƿ�֧�ֶϵ�����
	void startDownloader();       //��ʼ���أ���Ϊ�̺߳���
	void cleanTempFile();            //������ʱ�ļ�
	void mergeTempFile();           //�ϲ���ʱ�ļ�
	~HttpDownloader();
	//void threadMonitor();            //���̼߳�����
private:
	bool resumable;              //�Ƿ���Էֿ�����
	CURL *curl;                      //����CURL���͵�ָ��
	CURLcode res;                     //���ص���Ϣ
	CURLcode info;                   //��Ӧͷ��Ϣ
	int fileSize;                    //�ļ���С
	int threadNum = 8;           //�̸߳���
	int timeOut = 5000;         //time out 5000 ����
	const char* urlAddress;         //���ʵ�URL��ַs
	const char* fileAdress;              //�����ļ�λ��
	long int minSize;             //���̵߳���С��С
	//FILE *fp;            //�ļ�ָ��

};