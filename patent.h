#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <stdio.h>
#include <map>

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

	/** ���transfer�ܵĽṹ�� */
	void AddTransferStruct();

	/** �����ֵ */
	void CalculateDifference();

	/** �õ�����Dֵ */
	vector<double> GetFirestMaxDIndex();

	/** �������ݵ�Dֵ */
	vector<double> max_complete_socre;



private: 
	/** �洢��string */
	vector<vector<string>> str_vector;

	/** �洢���������� */
	vector<shared_ptr<Patent_Data_S>> patent_all_data;

	/** ˵����ҳ�� */
	vector<shared_ptr<Instruction_Num>> vector_instruction_num;

	/** ��ͼ���� */
	vector<shared_ptr<Image_Num>> vector_image_num;

	/** ������֤�� */
	vector<shared_ptr<Non_Patent_Citation_Num>> vector_non_patent_citation_num;

	/** ר����֤�� */
	vector<shared_ptr<Citation_Num>> vector_citation_num;

	/** ��֤����ר����*/
	vector<shared_ptr<Citation_Of_Domestic_Num>> vector_citation_of_domestic_num;

	/** ��֤���ר���� */
	vector<shared_ptr<Citation_Of_Foreign_Num>> vector_citation_of_foreign_num;

	/** ר����� */
	vector<shared_ptr<Patent_Type>> vector_patent_type;

	/** ������ */
	vector<shared_ptr<Term_Of_Patent_Protection>> vector_term_of_patent_protection;

	/** ������ */
	vector<shared_ptr<Classify_Num>> vector_classify_num;

	/** IPC������ */
	vector<shared_ptr<IPC_Large_Classify_Num>> vector_IPC_large_classify_num;

	/** IPCС���� */
	vector<shared_ptr<IPC_Sub_Classify_Num>> vector_IPC_sub_classify_num;

	/** ͬ��ר���� */
	vector<shared_ptr<Kin_Num>> vector_kin_num;

	/** ͬ�岼�ֹ��ҡ������� */
	vector<shared_ptr<Kin_Of_Country_Num>> vector_kin_of_country_num;

	/** �Ƿ�ΪPCT���� */
	vector<shared_ptr<PCT_Apply>> vector_PCT_apply;

	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	vector<shared_ptr<Five_Four_Countries_Patent>> vector_five_four_countries_patent;

	/** ר��������� */
	vector<shared_ptr<Country_code>>  vector_country_code;

	/** �����չ�����ʱ�������꣩*/
	vector<shared_ptr<Application_Open_Day_Interval>> vector_application_open_day_interval;

	/** ��������Ȩ��ʱ���� */
	vector<shared_ptr<Application_Authorization_Day_Interval>> vector_application_authorization_day_interval;

	/** ��������Ȩ��ʱ���� */
	vector<shared_ptr<Open_Authorization_Day_Interval>> vector_open_authorization_day_interval;

	/** ʣ����Ч�� */
	vector<shared_ptr<Survival_Time>> vector_survival_time;

	/** �Ƿ�������Ȩ */
	vector<shared_ptr<PRORITY>> vector_prority;

	/** Ȩ���� */
	vector<shared_ptr<Right_Num>> vector_right_num;

	/** �������� */
	vector<shared_ptr<Num_Of_Invention>> vector_num_of_invention;

	/** �������� */
	vector<shared_ptr<Num_Of_Application>> vector_num_of_application;

	/** ��ǰר��Ȩ���� */
	vector<shared_ptr<Current_Num_Of_Patent>> vector_current_num_of_patent;

	/** ���������� */
	vector<shared_ptr<Type_Of_Application>> vector_type_of_application;

	






	/** ˵����ҳ�� */
	shared_ptr<Transfer_Data> instruction_num_transfer;

	/** ��ͼ���� */
	shared_ptr<Transfer_Data> image_num_transfer;

	/** ������֤�� */
	shared_ptr<Transfer_Data> non_patent_citation_num_transfer;

	/** ר����֤�� */
	shared_ptr<Transfer_Data> citation_num_transfer;

	/** ��֤����ר����*/
	shared_ptr<Transfer_Data> citation_of_domestic_num_transfer;

	/** ��֤���ר���� */
	shared_ptr<Transfer_Data> citation_of_foreign_num_transfer;

	/** ר����� */
	shared_ptr<Transfer_Data> patent_type_transfer;

	/** ������ */
	shared_ptr<Transfer_Data> term_of_patent_protection_transfer;

	/** ������ */
	shared_ptr<Transfer_Data>  classify_num_transfer;

	/** IPC������ */
	shared_ptr<Transfer_Data> IPC_large_classify_num_transfer;

	/** IPCС���� */
	shared_ptr<Transfer_Data> IPC_sub_classify_num_transfer;

	/** ͬ��ר���� */
	shared_ptr<Transfer_Data> kin_num_transfer;

	/** ͬ�岼�ֹ��ҡ������� */
	shared_ptr<Transfer_Data> kin_of_country_num_transfer;

	/** �Ƿ�ΪPCT���� */
	shared_ptr<Transfer_Data> PCT_apply_transfer;

	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	shared_ptr<Transfer_Data> five_four_countries_patent_transfer;

	/** ר��������� */
	shared_ptr<Transfer_Data> country_code_transfer;

	/** �����չ�����ʱ�������꣩*/
	shared_ptr<Transfer_Data> application_open_day_interval_transfer;

	/** ��������Ȩ��ʱ���� */
	shared_ptr<Transfer_Data> application_authorization_day_interval_transfer;

	/** ��������Ȩ��ʱ���� */
	shared_ptr<Transfer_Data> open_authorization_day_interval_transfer;

	/** ʣ����Ч�� */
	shared_ptr<Transfer_Data> survival_time_transfer;

	/** �Ƿ�������Ȩ */
	shared_ptr<Transfer_Data> prority_transfer;

	/** Ȩ���� */
	shared_ptr<Transfer_Data> right_num_transfer;

	/** �������� */
	shared_ptr<Transfer_Data> num_of_invention_transfer;

	/** �������� */
	shared_ptr<Transfer_Data> num_of_application_transfer;

	/** ��ǰר��Ȩ���� */
	shared_ptr<Transfer_Data> current_num_of_patent_transfer;

	/** ���������� */
	shared_ptr<Transfer_Data> type_of_application_transfer;

	/** �ܵ�transfer�ṹ������ */
	vector<shared_ptr<Transfer_Data>> transfer_all_data;

	/** ��ʼ��Ⱥ�����ֵ */
	const double temp_num_init = 1000.0f;
};
