
class CoreApp {
private:
    Contact model;
    void list();
    void add();
    void edit();
    void remove();
public:
    CoreApp(char* dbName);
    init();
}