#pragma once
#include <string>
using namespace std;


/** ˳����� */
enum Enum_Patent
{
	/** ���׺� */
	E_literature = 0,
	/** �Ƿ�ת�� */
	E_transfer = 1,

	/**------------- ������ ---------*/
	/** ˵����ҳ�� */
	E_instruction_num = 2,
	/** ��ͼ���� */
	E_image_num = 3,
	/** ������֤�� */
	E_non_patent_citation_num = 4,
	/** ר����֤�� */
	E_citation_num = 5,
	/** ��֤����ר����*/
	E_citation_of_domestic_num = 6,
	/** ��֤���ר���� */
	E_citation_of_foreign_num = 7,

	/**------------ IPC�� -------------------*/
	/** ר����� */
	E_patent_type = 8,
	/** ������ */
	E_term_of_patent_protection = 9,
	/** ������ */
	E_classify_num = 10,
	/** IPC������ */
	E_IPC_large_classify_num = 11,
	/** IPCС���� */
	E_IPC_sub_classify_num = 12,
	/** ͬ��ר���� */
	E_kin_num = 13,

	/**------------ ���ʻ� -------------------*/
	/** ͬ�岼�ֹ��ҡ������� */
	E_kin_of_country_num = 14,
	/** �Ƿ�ΪPCT���� */
	E_PCT_apply = 15,
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	E_five_four_countries_patent = 16,
	/** ר��������� */
	E_country_code = 17,


	/** �����չ�����ʱ�������꣩*/
	E_application_open_day_interval = 18,
	/** ��������Ȩ��ʱ���� */
	E_application_authorization_day_interval = 19,
	/** ��������Ȩ��ʱ���� */
	E_open_authorization_day_interval = 20,
	/** ʣ����Ч�� */
	E_survival_time = 21,


	/** �Ƿ�������Ȩ */
	E_prority = 22,
	/** Ȩ���� */
	E_right_num = 23,


	/** �������� */
	E_num_of_invention = 24,
	/** �������� */
	E_num_of_application = 25,
	/** ר��Ȩ�˹�ģ */
	E_current_num_of_patent = 26,
	/** ���������� */
	E_type_of_application = 27,
};

struct  Patent_Data_S
{
	/** ���׺� */
	string literature;

	/** �Ƿ�ת�� */
	int transfer;

	/** ���ԣ�ÿ��ר��һ��Map) */
	map <Enum_Patent, double> all_patent_data_S_num;
};

struct Base_Struct
{
	/** ���׺� */
	string literature;

	/** �Ƿ�ת�� */
	int transfer;

	/** ���� */
	double num_of_feature;
};

struct Transfer_Data
{
	/** ת���ۼ��� */
	vector<double> transfer_add_index;

	/** δת���ۼ��� */
	vector<double> untransfer_add_index;

	/** ת���� */
	double untransfer_num;

	/** δת���� */
	double transfer_num;

	/** D���ֵ */
	double first_max_d;
};

struct RValueCL
{
	Enum_Patent first_value;
	Enum_Patent second_value;
	double r_value;
};