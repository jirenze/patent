#pragma once
#include <string>

using namespace std;

struct  Patent_Data_S
{
	/** ���׺� */
	string literature;

	/** �Ƿ�ת�� */
	int transfer;

	/** ˵����ҳ�� */
	double instruction_num;

	/** ��ͼ���� */
	double image_num;

	/** ������֤�� */
	double non_patent_citation_num;

	/** ר����֤�� */
	double citation_num;

	/** ��֤����ר����*/
	double citation_of_domestic_num;

	/** ��֤���ר���� */
	double citation_of_foreign_num;

	/** ר����� */
	float patent_type;

	/** ������ */
	float term_of_patent_protection;

	/** ������ */
	double classify_num;

	/** IPC������ */
	double IPC_large_classify_num;

	/** IPCС���� */
	double IPC_sub_classify_num;

	/** ͬ��ר���� */
	double kin_num;

	/** ͬ�岼�ֹ��ҡ������� */
	double kin_of_country_num;

	/** �Ƿ�ΪPCT���� */
	int PCT_apply;

	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	int five_four_countries_patent;

	/** ר��������� */
	int country_code;

	/** �����չ�����ʱ�������꣩*/
	double application_open_day_interval;

	/** ��������Ȩ��ʱ���� */
	double application_authorization_day_interval;

	/** ��������Ȩ��ʱ���� */
	double open_authorization_day_interval;

	/** ʣ����Ч�� */
	float survival_time;

	/** �Ƿ�������Ȩ */
	int prority;

	/** Ȩ���� */
	double right_num;

	/** �������� */
	double num_of_invention;

	/** �������� */
	float num_of_application;

	/** ר��Ȩ���� */
	float current_num_of_patent;

	/** ���������� */
	float type_of_application;
};

/** ˳����� */
enum Enum_Patent
{
	/** ���׺� */
	E_literature,

	/** �Ƿ�ת�� */
	E_transfer,

	/** ˵����ҳ�� */
	E_instruction_num,

	/** ��ͼ���� */
	E_image_num,

	/** ������֤�� */
	E_non_patent_citation_num,

	/** ר����֤�� */
	E_citation_num,

	/** ��֤����ר����*/
	E_citation_of_domestic_num,

	/** ��֤���ר���� */
	E_citation_of_foreign_num,

	/** ר����� */
	E_patent_type,

	/** ������ */
	E_term_of_patent_protection,

	/** ������ */
	E_classify_num,

	/** IPC������ */
	E_IPC_large_classify_num,

	/** IPCС���� */
	E_IPC_sub_classify_num,

	/** ͬ��ר���� */
	E_kin_num,

	/** ͬ�岼�ֹ��ҡ������� */
	E_kin_of_country_num,

	/** �Ƿ�ΪPCT���� */
	E_PCT_apply,

	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	E_five_four_countries_patent,

	/** ר��������� */
	E_country_code,

	/** �����չ�����ʱ�������꣩*/
	E_application_open_day_interval,

	/** ��������Ȩ��ʱ���� */
	E_application_authorization_day_interval,

	/** ��������Ȩ��ʱ���� */
	E_open_authorization_day_interval,

	/** ʣ����Ч�� */
	E_survival_time,

	/** �Ƿ�������Ȩ */
	E_prority,

	/** Ȩ���� */
	E_right_num,

	/** �������� */
	E_num_of_invention,

	/** �������� */
	E_num_of_application,

	/** ר��Ȩ�˹�ģ */
	E_current_num_of_patent,

	/** ���������� */
	E_type_of_application,
};


struct Base_Struct
{
	/** ���׺� */
	string literature;

	/** �Ƿ�ת�� */
	bool transfer;
};

struct Instruction_Num : Base_Struct
{
	/** ˵����ҳ�� */
	double instruction_num;
};

struct Image_Num : Base_Struct
{
	/** ��ͼ���� */
	double image_num;
};

struct Non_Patent_Citation_Num : Base_Struct
{
	/** ������֤�� */
	double non_patent_citation_num;
};

struct Citation_Num : Base_Struct
{
	/** ר����֤�� */
	double citation_num;
};

struct Citation_Of_Domestic_Num : Base_Struct
{
	/** ��֤����ר����*/
	double citation_of_domestic_num;
};

struct Citation_Of_Foreign_Num : Base_Struct
{
	/** ��֤���ר���� */
	double citation_of_foreign_num;
};

struct Patent_Type : Base_Struct
{
	/** ר����� */
	float patent_type;
};

struct Term_Of_Patent_Protection : Base_Struct
{
	/** ������ */
	float term_of_patent_protection;
};

struct Classify_Num : Base_Struct
{
	/** ������ */
	double classify_num;
};

struct IPC_Large_Classify_Num : Base_Struct
{
	/** IPC������ */
	double IPC_large_classify_num;
};

struct IPC_Sub_Classify_Num : Base_Struct
{
	/** IPCС���� */
	double IPC_sub_classify_num;
};

struct Kin_Num : Base_Struct
{
	/** ͬ��ר���� */
	double kin_num;
};

struct Kin_Of_Country_Num : Base_Struct
{
	/** ͬ�岼�ֹ��ҡ������� */
	double kin_of_country_num;
};

struct PCT_Apply : Base_Struct
{
	/** �Ƿ�ΪPCT���� */
	int PCT_apply;
};

struct Five_Four_Countries_Patent : Base_Struct
{
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	int five_four_countries_patent;
};

struct Country_code :Base_Struct
{
	/** ר��������� */
	int country_code;
};

struct Application_Open_Day_Interval : Base_Struct
{
	/** �����չ�����ʱ�������꣩*/
	double application_open_day_interval;
};

struct Application_Authorization_Day_Interval : Base_Struct
{
	/** ��������Ȩ��ʱ���� */
	double application_authorization_day_interval;
};

struct Open_Authorization_Day_Interval : Base_Struct
{
	/** ��������Ȩ��ʱ���� */
	double open_authorization_day_interval;
};

struct Survival_Time : Base_Struct
{
	/** ʣ����Ч�� */
	float survival_time;
};

struct PRORITY : Base_Struct
{
	/** �Ƿ�������Ȩ */
	int prority;
};

struct Right_Num : Base_Struct
{
	/** Ȩ���� */
	double right_num;
};

struct Num_Of_Invention : Base_Struct
{
	/** �������� */
	double num_of_invention;
};

struct Num_Of_Application : Base_Struct
{
	/** �������� */
	float num_of_application;
};

struct Current_Num_Of_Patent : Base_Struct
{
	/** ר��Ȩ���� */
	float current_num_of_patent;
};

struct Type_Of_Application : Base_Struct
{
	/** ���������� */
	float type_of_application;
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
