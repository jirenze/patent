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

	/**------------- ��֤�� ---------*/
	/** ר������֤�� */
	E_citation_cited_num = 8,
	/** ������ר����֤�� */
	E_citation_cited_of_domestic_num = 9,
	/** �����ר����֤�� */
	E_citation_cited_of_foreign_num = 10,
	/** 5���ڱ���֤�� */
	E_citation_cited_of_five_year = 11,

	/**------------ IPC�� -------------------*/
	/** ר����� */
	E_patent_type = 12,
	/** ������ */
	E_term_of_patent_protection = 13,
	/** ������ */
	E_classify_num = 14,
	/** IPC������ */
	E_IPC_large_classify_num = 15,
	/** IPCС���� */
	E_IPC_sub_classify_num = 16,
	/** ͬ��ר���� */
	E_kin_num = 17,

	/**------------ ���ʻ� -------------------*/
	/** ͬ�岼�ֹ��ҡ������� */
	E_kin_of_country_num = 18,
	/** �Ƿ�ΪPCT���� */
	E_PCT_apply = 19,
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	E_five_four_countries_patent = 20,
	/** ר��������� */
	E_country_code = 21,

	/**------------ ʱ���� -------------------*/
	/** �����չ�����ʱ�������꣩*/
	E_application_open_day_interval = 22,
	/** ��������Ȩ��ʱ���� */
	E_application_authorization_day_interval = 23,
	/** ��������Ȩ��ʱ���� */
	E_open_authorization_day_interval = 24,
	/** ����� */
	E_survival_time = 25,

	/**------------ Ȩ���� -------------------*/
	/** �Ƿ�������Ȩ */
	E_prority = 26,
	/** Ȩ���� */
	E_right_num = 27,
	/** �Ƿ��轻ר���� */
	E_renewal_of_patent_fees = 28,
	/** �Ƿ���Ѻ */
	E_pledge = 29,
	/** �Ƿ��� */
	E_review =30,


	/**------------ �����ˡ������� -------------------*/
	/** �������� */
	E_num_of_invention = 31,
	/** �������� */
	E_num_of_application = 32,
	/** ר��Ȩ�˹�ģ */
	E_current_num_of_patent = 33,
	/** ���������� */
	E_type_of_application = 34,
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
