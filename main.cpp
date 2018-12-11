#include <iostream>

using namespace std;
bool isnumeric(string st) {
    cout << "entering isnumeric" << endl;
	    int len = st.length();
	    for (int i = 0; i < len; i++) {
	        if (int(st[i])<48 || int(st[i]) > 57) {
	        	cout << "not numeric" << endl;
	            return false;
	        }


	    }
	    cout << "is numeric" << endl;
	    return true;
	}

bool parse_beginning_numeric_and_unit(string first_word, string &street_num, string &unit_num)	{
        string num_part;
        string unit_part;
        cout << "entering Parse unit" << endl;

        //bool num_found = 0;
        int counter = 0;
            int len = first_word.length();
        for(int i = 0; i < len; i++ ){
            if (int(first_word[i])>=48 && int(first_word[i]) <= 57){
                num_part = num_part + first_word[i];
                cout << first_word[i] << endl;
                //num_found = 1;
                counter++;
            }

        }
        cout << num_part << endl;
        
        if (counter < first_word.length()){
            // remainder is unit num.
            unit_num = first_word.substr(counter,255);
            street_num = num_part;
            cout << unit_num << " "  << street_num << endl;
        }
    return 0;
}

bool found_in_array(string input, const string search_array[], int sizeof_ary){
	for (int i=0; i < sizeof_ary; i++){
		if (input == search_array[i]){
			return 1;
		}
	else {
		return 0;
		}
	}
}

string pop_first_word(string &remaining_address){
	int position = remaining_address.find(" ");
	string first_word = remaining_address.substr(0,position);
    remaining_address = remaining_address.substr(position+1);
    return first_word;
}

int main(){
    string cardinal_ary[24] = {"E","East", "ENE",  "ESE",  "N", "NE", "NNE", "NNW", "North", "Northeast", "NW", "S", "SE", "South",\
                                "Southeast", "Southwest", "SSE", "SSW", "SW", "W","West",  "WNW", "WSW"};

	string street_Type_ary[20]= {"Av", "Ave", "Avenue","Blvd", "Boulevard", "Cir", "Circle","Ct",\
                                "Court",  "Highway", "HW", "HWY", "Ln", "Lane",  "Rd", "Road", "St", "Street", "Wy", "Way"};

    string states_ary[102]={"Alabama", "AL", "Alaska", "AK", "Arizona", "AZ", "Arkansas", "AR", "California", "CA",\
                            "Colorado", "CO", "Connecticut", "CT","Delaware", "DE", "District of Columbia", "DC", "Florida",\
							"FL", "Georgia", "GA", "Hawaii", "HI", "Idaho", "ID", "Illinois", "IL", "Indiana",\
                            "IN", "Iowa", "IA", "Kansas", "KS", "Kentucky", "KY", "Louisiana", "LA", "Maine", "ME"\
                            "Montana", "MT", "Nebraska", "NE", "Nevada", "NV", "New Hampshire", "NH", "New Jersey",\
                            "NJ", "New Mexico", "NM", "New York", "NY", "North Carolina", "NC",\
                            "North Dakota", "ND", "Ohio", "OH", "Oklahoma", "OK", "Oregon", "OR", "Maryland", "MD", \
                            "Massachusetts", "MA", "Michigan", "MI", "Minnesota", "MN",\
                            "Mississippi", "MS", "Missouri", "MO", "Pennsylvania", "PA", "Rhode Island", "RI", \
                            "South Carolina", "SC", "South Dakota", "SD", "Tennessee", "TN",\
                            "Texas", "TX", "Utah", "UT", "Vermont", "VT", "Virginia", "VA", "Washington", "WA", "West Virginia", "WV",\
                            "Wisconsin", "WI", "Wyoming", "WY"};

    string po_ary[3] = {"PO", "P.O.", "Post"};

    string cr_ary[3]={"CR", "County", "C.R."};


	//saves original strings in case need to back out
	string address_string = "820A Fetzer Ct.";
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
        string po_box_yn;
        string po_box_num;
        string hwy_yn;
        string hwy_name;
        string hwy_num;
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
		//position = address_work_string.find(" ");
		
		pop_first_word(address_work_string);
		
        //first_word = address_work_string.substr(0,position);
        //address_work_string = address_work_string.substr(position+1);
        
        cout << first_word << endl;
        cout << address_work_string << endl;



		if (isnumeric(first_word)){
            // save as street_num
            address.street_num = first_word;
            cout << "address.street_num " << address.street_num << endl;
		}
		//does it start with a numeral
		else if (isnumeric(string(1,first_word[0]))) {
			
            // yes
                //parse number from unit
                // MAKE THIS ANSWER THE QUESTION "STARTS WITH NUMERAL"
                parse_beginning_numeric_and_unit(first_word,  address.street_num,  address.unit_designator);
                cout << "wasn't numeric" << endl;
            }
        
        
            // no
            //does it start with PO
		else if (found_in_array(first_word, po_ary, sizeof(po_ary) / sizeof(po_ary[0])) ){
		
                	address.po_box_yn= 1;
    	}
				
    	        //does it start with HWY
                //does it start with STATE
                //does it start with CR
                //does it have 1/2
                //does it have unit number

		
		
 		cout << "address.street_num " << address.street_num << endl;
 		cout << "address.unit_designator " << address.unit_designator << endl;
    return 0;
}

