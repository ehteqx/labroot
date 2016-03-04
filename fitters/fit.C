
// *** *** ROOT-POWERED LEAST SQUARES USER-DEFINED FITTER *** *** //
// 		   USING: Root (framework), Minuit (fitter LSQ), Migrad (minimizer)

double fitfunc(double* x, double* p) {		// USER-DEFINED FIT ROUTINE

   double fitval;

// Modify as needed: x[0] = x value; p[i] = i-th parameter // EDIT ALSO THE LINE WITH ### (Guesses and Names)

/*
	EXPONENTIAL:   	fitval = p[0] + exp(p[1] +(x[0])*(p[2]));	// PARAM: 3
	LINEAR:			fitval = p[0] + x[0] * p[1];				// PARAM: 2
*/

   return fitval;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fit() {		// DATA-INPUT ROUTINE

   const int mpt = 9999;	// Max. points to fit (as you like)
   float x1[mpt];
   float x2[mpt];
   float x3[mpt];

   int npt = 0;		// Initial counter

   // Read data from file...
   ifstream in;
   in.open("dat.txt");		// Eventually change filename
   while (1) {

      in >> x1[npt] >> x2[npt] >> x3[npt];

      if ( ! in.good() ) break;			// ...and stop when data columns finish

      cout << "x = " << x1[npt] << " y = " << x2[npt] << " ey = " << x3[npt]  << endl;

      npt++;

   }

   in.close();		// Close file

   printf(" Found %d points\n", npt);		// Output: Number of points found in file

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   TCanvas* c1 = new TCanvas("c1", "Points, Errors and Best Fit", 0, 0, 500, 500);

   TGraphErrors* gr = new TGraphErrors(npt, x1, x2, 0, x3);		// Add here (eventually) error on x-es

   TF1* f1 = new TF1("f1", fitfunc, 0.00, 10.00, 2);	// LAST NUMBER --> Number of parameters to fit

   // INITIAL GUESSES AND PARAMETER NAMES ################################################################
   f1->SetParameters(-0.1, 1.1);
   f1->SetParNames("y off", "xmult off");

   // Print first graph (Points, Fit, Errors)
   gStyle->SetOptFit(kTRUE);

   c1->cd();
   gr->Fit("f1");
   gr->Draw("AP");
   c1->Clear();
   gr->Draw("AP");

   gr->SetLineColor(kBlue);
   gr->Draw("AP");
   f1->SetLineColor(kRed);
   f1->Draw("same");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TH1F* h1 = new TH1F("h1", "Regression Residues", 20, -10.0, 10.0); // Graph of regression residues (n°BINS, START, STOP)

   for (int i=0; i < npt; i++) {
     float resid = (x2[i]-f1->Eval(x1[i]))/x3[i];
     h1->Fill(resid);
   }

   TCanvas* c2 = new TCanvas("c2", "Regression Residues", 600, 0, 500, 500);

   TF1* f = new TF1("fgaus", "gaus", -2.0, 2.0);		// Gaussian fit of the residues histogram

   f->SetParameters(3.0, 0.0, 1.0); // Initial parameters (LEAVE THEM ALONE!)

   c2->cd();
   h1->Fit(f);

// Linearization of residues...
   float y2[mpt];

   for (int i=0; i < npt; i++) {
     y2[i] = (x2[i]-f1->Eval(x1[i]));
   }

	// Linear residues plot
   TCanvas* c3 = new TCanvas("c3", "Regression Residues (linearized)", 300, 300, 500, 500);

   TGraphErrors* gr1 = new TGraphErrors(npt, x1, y2, 0, x3);	// Add here (eventually) error on x-es

   TF1 *g1 = new TF1("g1", "pol1", 0.00, 10.00);	// First-order polynomial fit

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Print everything on screen
   c3->cd();
   gr1->Fit("g1");
   gr1->Draw("AP");
   c3->Clear();
   gr1->Draw("AP");

   gr1->SetLineColor(kBlue);
   gr1->Draw("AP");
   g1->SetLineColor(kRed);
   g1->Draw("same");

}

