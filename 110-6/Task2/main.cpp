#include <iostream>
<<<<<<< HEAD
#include <string>
=======
#include <sstream>
>>>>>>> 5b26b6ac896b8192a8bb08c50a64ba3bc7f83776

using namespace std;

#include "xAxis.h"

int main()
{
<<<<<<< HEAD
    string names[] = {"Daniel", "John", "Cait", "Reece"};
    double vals[] = {123, 23.3, 13.333, 12};

    xAxis c(4, names, vals);
    c.display();
    cout << endl;
    c.deleteNode( "John" );
    c.display();
    c.increaseValueBy( "Cait", 23.34);
    c.display();
    cout << endl;
    c.decreaseValueBy( "Daniel", 100);
    c.display();
    cout << endl;
    c.changeLabel( "Daniel", "Cumguzzler");
    c.display();
    cout << endl;
    c.shorten();
    cin.ignore();
    c.display();
    cout << endl;  
    cout << endl;
}
=======
    string ar[3] = {"aaa", "bbb", "ccc"};
    double dar[3] = {111, 222, 333};

    xAxis xA(3, ar, dar);

    xA.display();

    xA.deleteNode("aaa");
    xA.deleteNode("bbb");
    xA.deleteNode("ccc");

    xA.display();
    cout << endl;
cout << "em" << endl;
    cout << endl;

    xA.extend( 23.4, "TwoThree" );
    xA.extend( 12.222, "OneTwo" );
    xA.extend( 13.13, "OneThree" );
    xA.display();
cout << endl;

    xA.shorten();
    xA.display();
cout << endl;

    xA.increaseValueBy("OneTwo", 2222);
    xA.display();
cout << endl;

    xA.decreaseValueBy("OneTwo", 3333 );
    xA.display();
cout << endl;

    xA.changeLabel( "TwoThree", "ThreeTwo" );
    xA.display();
cout << endl;

    xA.extend( 1234, "All" );
    xA.display();
cout << endl;

    xA.deleteNode( "OneTwoThree" );
    xA.display();
cout << endl;

    xA.deleteNode( "OneTwo" );
    xA.display();
cout << endl;

  for(int i = 0; i < 100; ++i) {
    xA.shorten();
  }
  xA.display();
  cout << endl;
/*
  string* labels = new string[3];
  labels[0] = "one";
  labels[1] = "two";
  labels[2] = "three";

  double* values = new double[3];
  values[0] = 2.3;
  values[1] = 1.2;
  values[2] = 2.2;

  xAxis x(3, labels, values);

  ostringstream result;
  result << "one\t2.3\ntwo\t1.2\nthree\t2.2\n";

  ostringstream output;

  x.display();
  cout << endl;
  cout << result.str();
  cout << endl << endl;
*/
string* labels = new string[1];
labels[0] = "one";

double* values = new double[1];
values[0] = 2.3;

xAxis x(1, labels, values);

x.shorten();

ostringstream result;
result << "";



  x.display();
  cout << endl;
  cout << result.str();
  cout << endl << endl;
}
>>>>>>> 5b26b6ac896b8192a8bb08c50a64ba3bc7f83776
