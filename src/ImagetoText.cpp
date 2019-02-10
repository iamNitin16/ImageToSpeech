/*
  Command :- g++ -o ImagetoText ImagetoText.cpp -llept -ltesseract
*/


#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include<fstream>
#include<iostream>


using namespace std;

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Not sufficient arguments\n");
    exit(-1);
  }

  char *outText ;
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  // Initialize tesseract-ocr with English, without specifying tessdata path
  if (api->Init(NULL, "eng")) {
      fprintf(stderr, "Could not initialize tesseract.\n");
      exit(1);
  }

  ofstream fout ;
  fout.open("example.txt");

  Pix *image = pixRead(*(argv+1));
  api->SetImage(image);
  // Get OCR result
  outText = api->GetUTF8Text();
  fout << outText;

  printf("OCR output:\n%s", outText);

  // Destroy used object and release memory
  api->End();
  delete [] outText;
  pixDestroy(&image);

  return 0;
}
