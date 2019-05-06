#pragma once
#include <string>

using namespace std;

struct  Patent_Data_S
{
	/** ���׺� */
	map<Enum_Patent, string> literature;

	/** �Ƿ�ת�� */
	map < Enum_Patent, int> transfer;

	/** ˵����ҳ�� */
	map < Enum_Patent, double> instruction_num;

	/** ��ͼ���� */
	map < Enum_Patent, double> image_num;

	/** ������֤�� */
	map < Enum_Patent, double> non_patent_citation_num;

	/** ר����֤�� */
	map < Enum_Patent, double> citation_num;

	/** ��֤����ר����*/
	map < Enum_Patent, double> citation_of_domestic_num;

	/** ��֤���ר���� */
	map < Enum_Patent, double> citation_of_foreign_num;

	/** ר����� */
	map < Enum_Patent, double> patent_type;

	/** ������ */
	map < Enum_Patent, double> term_of_patent_protection;

	/** ������ */
	map < Enum_Patent, double> classify_num;

	/** IPC������ */
	map < Enum_Patent, double> IPC_large_classify_num;

	/** IPCС���� */
	map < Enum_Patent, double> IPC_sub_classify_num;

	/** ͬ��ר���� */
	map < Enum_Patent, double> kin_num;

	/** ͬ�岼�ֹ��ҡ������� */
	map < Enum_Patent, double> kin_of_country_num;

	/** �Ƿ�ΪPCT���� */
	map < Enum_Patent, double> PCT_apply;

	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	map < Enum_Patent, double> five_four_countries_patent;

	/** ר��������� */
	map < Enum_Patent, double> country_code;

	/** �����չ�����ʱ�������꣩*/
	map < Enum_Patent, double> application_open_day_interval;

	/** ��������Ȩ��ʱ���� */
	map < Enum_Patent, double> application_authorization_day_interval;

	/** ��������Ȩ��ʱ���� */
	map < Enum_Patent, double> open_authorization_day_interval;

	/** ʣ����Ч�� */
	map < Enum_Patent, double> survival_time;

	/** �Ƿ�������Ȩ */
	map < Enum_Patent, double> prority;

	/** Ȩ���� */
	map < Enum_Patent, double> right_num;

	/** �������� */
	map < Enum_Patent, double> num_of_invention;

	/** �������� */
	map < Enum_Patent, double> num_of_application;

	/** ר��Ȩ���� */
	map < Enum_Patent, double> current_num_of_patent;

	/** ���������� */
	map < Enum_Patent, double> type_of_application;
};

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


struct Base_Struct
{
	/** ���׺� */
	string literature;

	/** �Ƿ�ת�� */
	bool transfer;

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