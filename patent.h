#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <stdio.h>
#include <map>
#include <set>

#include "PatentStruct.h"
#include "patent.h"
	
using namespace std;

class Patent
{
public:
	Patent();
	~Patent() {};

	/** ��ȡcsv�ļ� */
	void ReadCSV();
	/** д��csv�ļ� */
	void WriteCSV();
	/** �������ݣ��ṹ��д�� */
	void PickCSVData();

	/** д����ԵĽṹ�� */
	void PickEveStruct();

	/** ���� */
	void SortForEveVector();

	/** �ۼ�EVE */
	void TransferOfAccumulation();

	/** �����ֵ */
	void CalculateDifference();

	/** �������ָ��ľ�ֵ */
	void CalculateAverage();

	/** ����Rֵ */
	void CalculateRValue();

	/** ɸѡRֵ */
	void SelectRvalue();
	
	/** �õ�����Rֵɸѡ���Dֵ��ָ������ */
	void SelectRafterD();

	/** ����W */
	void CalculateWValue();

	/** ����Z */
	void CalculateZValue();
public: 
	/** �õ�����Dֵ */
	vector<double> GetFirestMaxDIndex();
	/** �������ݵ�Dֵ */
	vector<double> max_complete_socre;
	/** ����ָ��ľ�ֵ */
	map<Enum_Patent, double> R_average;


	/**-------- Rֵ ------*/
	/** �������ݵ�Rֵ ������ */
	vector<RValueCL> R_value_Technology;
	/** �������ݵ�Rֵ IPC */
	vector<RValueCL> R_value_IPC;
	/** �������ݵ�Rֵ ���ʻ� */
	vector<RValueCL> R_value_Internationalization;
	/** �������ݵ�Rֵ ʱ�� */
	vector<RValueCL> R_value_Time;
	/** �������ݵ�Rֵ Ȩ���� */
	vector<RValueCL> R_value_Right;
	/** �������ݵ�Rֵ ������ ������ */
	vector<RValueCL> R_value_Inventor;
	
	/** ����0.7 ɸѡʣ�µ�ָ�� */
	vector<Enum_Patent> selected_enum_patent;
private:

	/** ����Rֵ �����ߣ�*/
	void CalculateRValueM(Enum_Patent in_enum_first, Enum_Patent in_enum_second, vector<RValueCL>& in_R_value);

	/** ɸѡRֵ (����)*/
	void SelectRvalueM(vector<RValueCL>& in_R_value);

	/** ���ö�٣�����ɸѡ */
	void AddEnumPatent();


private: 
	/** �洢��string */
	vector<vector<string>> str_vector;

	/** �洢���������� */
	vector<shared_ptr<Patent_Data_S>> patent_all_data;

	/** �洢���������� */
	map<Enum_Patent,vector<shared_ptr<Base_Struct>>> vector_base_struct_num;

	/** �ܵ�transfer�ṹ������ */
	map<Enum_Patent,shared_ptr<Transfer_Data>> transfer_all_data;

	/** ����Rֵɸѡ���Dֵtransfer�ṹ������ */
	map<Enum_Patent, shared_ptr<Transfer_Data>> transfer_after_data;

	/** w�ܵ�Ȩ�� */
	map<Enum_Patent, double> w_data;




	/** �洢������ö��ֵ */
	vector<Enum_Patent> all_enum_patent;

	/** ��ʼ��Ⱥ�����ֵ */
	const double temp_num_init = 1000.0f;
};

