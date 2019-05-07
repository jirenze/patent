#pragma once
#include <string>
using namespace std;


/** 顺序参照 */
enum Enum_Patent
{
	/** 文献号 */
	E_literature = 0,
	/** 是否转让 */
	E_transfer = 1,

	/**------------- 技术类 ---------*/
	/** 说明书页数 */
	E_instruction_num = 2,
	/** 附图个数 */
	E_image_num = 3,
	/** 文献引证数 */
	E_non_patent_citation_num = 4,
	/** 专利引证数 */
	E_citation_num = 5,
	/** 引证本国专利数*/
	E_citation_of_domestic_num = 6,
	/** 引证外国专利数 */
	E_citation_of_foreign_num = 7,

	/**------------ IPC类 -------------------*/
	/** 专利类别 */
	E_patent_type = 8,
	/** 保护期 */
	E_term_of_patent_protection = 9,
	/** 分类数 */
	E_classify_num = 10,
	/** IPC大类数 */
	E_IPC_large_classify_num = 11,
	/** IPC小类数 */
	E_IPC_sub_classify_num = 12,
	/** 同族专利数 */
	E_kin_num = 13,

	/**------------ 国际化 -------------------*/
	/** 同族布局国家、地区数 */
	E_kin_of_country_num = 14,
	/** 是否为PCT申请 */
	E_PCT_apply = 15,
	/** 是否为五国专利/四方专利 */
	E_five_four_countries_patent = 16,
	/** 专利国别代码 */
	E_country_code = 17,


	/** 申请日公开日时间间隔（年）*/
	E_application_open_day_interval = 18,
	/** 申请日授权日时间间隔 */
	E_application_authorization_day_interval = 19,
	/** 公开日授权日时间间隔 */
	E_open_authorization_day_interval = 20,
	/** 剩余有效期 */
	E_survival_time = 21,


	/** 是否有优先权 */
	E_prority = 22,
	/** 权项数 */
	E_right_num = 23,


	/** 发明人数 */
	E_num_of_invention = 24,
	/** 申请人数 */
	E_num_of_application = 25,
	/** 专利权人规模 */
	E_current_num_of_patent = 26,
	/** 申请人类型 */
	E_type_of_application = 27,
};

struct  Patent_Data_S
{
	/** 文献号 */
	string literature;

	/** 是否转让 */
	int transfer;

	/** 属性（每个专利一个Map) */
	map <Enum_Patent, double> all_patent_data_S_num;
};

struct Base_Struct
{
	/** 文献号 */
	string literature;

	/** 是否转让 */
	int transfer;

	/** 属性 */
	double num_of_feature;
};

struct Transfer_Data
{
	/** 转让累加数 */
	vector<double> transfer_add_index;

	/** 未转让累加数 */
	vector<double> untransfer_add_index;

	/** 转让数 */
	double untransfer_num;

	/** 未转让数 */
	double transfer_num;

	/** D最大值 */
	double first_max_d;
};

struct RValueCL
{
	Enum_Patent first_value;
	Enum_Patent second_value;
	double r_value;
};