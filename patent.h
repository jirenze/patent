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


	/** ����W ȫָ�� */
	void CalculateWValueFull(map<Enum_Patent, double>& in_w_data_fifter_for_z);

	/** ����W ѭ��ָ�� */
	void CalculateWValueDelete(map<Enum_Patent, map<Enum_Patent, double>>& in_w_data);

	/** ����Z��ȫָ�� */
	void CalculateZValueFull(vector<Enum_Patent>& in_selected_enum_patent, vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, map<Enum_Patent, double>& in_w_data_fifter_for_z);

	/** ����Z��ѭ��ָ�� */
	void CalculateZValueDelete(vector<Enum_Patent>& in_selected_enum_patent, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector, map<Enum_Patent, map<Enum_Patent, double>>& in_w_data_fifter_for_all);


	/** ����Z_total��Dֵ��ȫָ�� */
	void CalculateZtotalDFull(vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, shared_ptr<Transfer_Data>& in_Z_fifter_full_transfer);

	/** ����Z_total��Dֵ��ѭ��ָ�� */
	void CalculateZtotalDDelete(map<Enum_Patent, shared_ptr<Transfer_Data>>& in_Z_fifter_delete_transfer, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector);



	/** ѭ������ָ�� */
	void CalculateIndexForW();

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

	/** �洢������ö��ֵ */
	vector<Enum_Patent> all_enum_patent;

	/** ��ʼ��Ⱥ�����ֵ */
	const double temp_num_init = 1000.0f;


private:
	/** ɸѡ���Wֵ  ��������û��ȥ��ָ���Zֵ */
	map<Enum_Patent, double> w_data_fifter_for_z;
	/** ɸѡ���Wֵ ˳��ȥ��ָ�� */
	map<Enum_Patent, map<Enum_Patent, double>> w_data_fifter_for_all;


	/** ɸѡ��Z����ֵ�� û��ȥ��ָ�� */
	vector<shared_ptr<Base_Struct>> Z_fifter_full_vector;
	/** ɸѡ��� �ܵ�Zֵ ˳��ȥ��ָ�� */
	map<Enum_Patent, vector<shared_ptr<Base_Struct>>> Z_fifter_delete_vector;

	/** �ܵ�Zֵ�ṹ������ */
	shared_ptr<Transfer_Data> Z_fifter_full_transfer;
	/** �ܵ�Zֵ�ṹ������ ˳��ȥ��ָ�� */
	map<Enum_Patent,shared_ptr<Transfer_Data>> Z_fifter_delete_transfer;

	/** ��ֹѭ�� */
	bool end_ok;
};

