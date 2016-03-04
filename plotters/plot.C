
void plot() {

   const int mpt = 9999;
   float x1[mpt];
   float x2[mpt];
   float x3[mpt];

   int npt = 0;

   // read data file
   ifstream in;
   in.open("dat.txt");

   while ( kTRUE ) {

      in >> x1[npt] >> x2[npt] >> x3[npt];

      if ( ! in.good() ) break;

      cout << "x = " << x1[npt] << " y = " << x2[npt] << " ey = " << x3[npt]  << endl;

      npt++;

   }

   in.close();

   printf(" found %d points\n", npt);

   TCanvas* c1 = new TCanvas("c1", "c1", 0, 0, 500, 500);

   TGraphErrors* gr = new TGraphErrors(npt, x1, x2, 0, x3);

   gStyle->SetOptStat(kTRUE);

   c1->cd();
   gr->Draw("AP");
   c1->Clear();
   gr->Draw("AP");

}
