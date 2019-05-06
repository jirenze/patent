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
	
	/** ����Dֵ */
	void ManageD();

	/** ����Rֵ */
	void ManageR();

	/** ����W Zֵ */
	void ManageWZ();

	/** ����ָ�� */
	void ManageIndex();
public:


	/** �������ݣ��ṹ��д�� */
	void PickCSVData();

	/** д����ԵĽṹ�� */
	void PickEveStruct();

	/** ���� */
	void SortForEveVector();

	/** �ۼ�EVE */
	void TransferOfAccumulation();

	/** �����ֵDֵ */
	void CalculateDifference();

	/** �������ָ��ľ�ֵ */
	void CalculateAverage();

	/** ����Rֵ */
	void CalculateRValue();

	/** ɸѡRֵ */
	void SelectRvalue();


	/** ����W */
	void CalculateWValue(map<Enum_Patent, double>& in_w_data);

	/** ����Z */
	void CalculateZValue(vector<Enum_Patent>& in_all_enum_patent, vector<shared_ptr<Base_Struct>>& in_Z_total_vector, map<Enum_Patent, double> in_w_data);

	/** ����Z_total��Dֵ */
	void CalculateZtotalD(vector<shared_ptr<Base_Struct>>& in_Z_total_vector, shared_ptr<Transfer_Data>& in_Z_total_transfer);


	/** ѭ������ָ�� */
	void CalculateIndexFor();

	/** �Ƚϳ���ָ��� ʣ�µ�ָ�� */
	void LeftoverIndex();

public: 
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
	
private:

	/** ����Rֵ �����ߣ�*/
	void CalculateRValueM(Enum_Patent in_enum_first, Enum_Patent in_enum_second, vector<RValueCL>& in_R_value);

	/** ɸѡRֵ (����)*/
	void SelectRvalueM(vector<RValueCL>& in_R_value);

	/** ���ö�٣�����ɸѡ */
	void AddEnumPatent();

	/** �õ�����Rֵɸѡ���Dֵ��ָ������ */
	void SelectRafterD();

	/** ѭ���������1��ָ����Zֵ�������ݽṹ */
	void CalculateZFifter();
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
	/** ����0.7 ɸѡʣ�µ�ָ�� */
	vector<Enum_Patent> selected_enum_patent;
	/** ȥ����ָ�� */
	vector<Enum_Patent> pass_selected_enum_patent;

	///** w�ܵ�Ȩ�� */
	//map<Enum_Patent, double> w_data;

	/** �ܵ�Zֵ */
	vector<shared_ptr<Base_Struct>> Z_total_vector;
	/** �ܵ�Zֵ�ṹ������ */
	shared_ptr<Transfer_Data> Z_total_transfer;

	/** �洢������ö��ֵ */
	vector<Enum_Patent> all_enum_patent;

	/** ��ʼ��Ⱥ�����ֵ */
	const double temp_num_init = 1000.0f;


private:
	/** ɸѡ���Wֵ  ��������û��ȥ��ָ���Zֵ */
	map<Enum_Patent, double> w_data_fifter_for_z;
	/** ɸѡ���Wֵ ˳��ȥ��ָ�� */
	map<Enum_Patent, map<Enum_Patent, double>> w_data_fifter;


	/** ɸѡ��Z����ֵ�� û��ȥ��ָ�� */
	vector<shared_ptr<Base_Struct>> Z_fifter_total_vector;
	/** �ܵ�Zֵ�ṹ������ */
	shared_ptr<Transfer_Data> Z_fifter_total_transfer;

	/** ɸѡ��� �ܵ�Zֵ ˳��ȥ��ָ�� */
	map<Enum_Patent, vector<shared_ptr<Base_Struct>>> Z_fifter_transfer;
	/** �ܵ�Zֵ�ṹ������ ˳��ȥ��ָ�� */
	map<Enum_Patent,shared_ptr<Transfer_Data>> Z_total_fifter_transfer;

	/** ��ֹѭ�� */
	bool end_ok;
};

