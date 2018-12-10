#include <iostream>

using namespace std;
bool isnumeric(string st) {
	    int len = st.length();
	    for (int i = 0; i < len; i++) {
	        if (int(st[i])<48 || int(st[i]) > 57) {
	            return false;
	        }
	    }
	    return true;
	}
int main()
{
     //card_ary = ["E","East", "ENE",  "ESE",  "N", "NE", "NNE", "NNW", "North", "Northeast", "NW", "S", "SE", "South", "Southeast", "Southwest", "SSE", "SSW", "SW", "W","West",  "WNW", "WSW"];
	 //str_ary = ["Av", "Ave", "Avenue","Blvd", "Boulevard", "Cir", "Circle","Ct", "Court",  "Highway", "HW", "HWY", "Ln", "Lane",  "Rd", "Road", "St", "Street", "Wy", "Way"];

	//saves original in case need to backtrack
	string address_string = "820 Fetzer Ct., Oakley, CA. 94561";
	string name_string = "Dwight David Shackelford";
	string locale_string = "Oakley, CA 94561";

	//one that gets chewed up in process
	string address_work_string = address_string;
	string name_work_string = name_string;
	string locale_work_string = locale_string;

	// bit pulled off each time
	string chunk = "";
    int position = -1;

    string first_word="";

	//initiate structure
	struct address_struct
	{
        string full_address;
        string street_num;
        string street_num_fract;
        string pre_cardinal;
        string street_name;
        string numeric_street_name_alpha;
        string street_type;
        string post_cardinal;
        string unit_type;
        string unit_designator;
    } address;

	struct locale_struct{
			string full_locale;
			string city;
			string state;
			string province;
			string postal_code;
			string postal_code_suffix;
			string country;
		};

	struct name_struct{
            string first_name;
			string nick_name;
			string middle_name;
			string last_name;
			string title;
			string generational;
			string business_name;
		} ;

        //name_struct address = new(address_struct);



		// Get the first word up to a space
        cout << address_work_string << endl;
		position = address_work_string.find(" ");
        first_word = address_work_string.substr(0,position);
        address_work_string = address_work_string.substr(position+1);



		if (isnumeric(first_word)){
            // save as street_num
            address.street_num = first_word;
            cout << address.street_num << endl;
            cout << first_word << endl;
		}
		else {
            //does it start with PO
            //does it start with HWY
            //does it start with STATE
            //does it start with CR
            //does it have 1/2
            //does it have unit number

		}

    return 0;
}

