vector< int >arr;
string input;
getline(cin, input);
istringstream is(input);
int num;
char c;
while(true)
{
    is>>num;
    arr.push_back(num);
    if(!is.eof()) is>>c;
    else break;
}
