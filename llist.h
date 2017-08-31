class llist
{
  private:
    record *    start;
    string        filename;
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(string);
    ~llist();
    int addRecord (int, string, string, int);
    int printRecord (int);
    int modifyRecord (int, string);
    void printAll();
    int deleteRecord(int);
    void reverse();
    friend ostream & operator << (ostream&,llist&);
};
