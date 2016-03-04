
void gauss() {

  ofstream out;
  out.open("dat.txt");

  for ( int i = 0; i < 1000; i++ ) {

    float g = gRandom->Gaus(-5.5, 0.5);

    cout << "i = " << i << " gauss = " << g << endl;

    out << g << endl;

  }

  out.close();

}
