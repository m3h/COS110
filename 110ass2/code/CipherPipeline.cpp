#include "CipherPipeline.h"

string CipherPipeline::encode(string plaint)
{
  for(int i = 0; i < pipeline.size(); ++i) {

    plaint = pipeline[i]->encode(plaint);
  }

  return plaint;
}

string CipherPipeline::decode(string ciphert)
{
  for(int i = pipeline.size()-1; i >= 0; --i) {

    ciphert = pipeline[i]->decode(ciphert);
  }

  return ciphert;
}

CipherPipeline& CipherPipeline::operator +=( Cipher * cip)
{
  pipeline.push_back( cip );

  return *this;
}

CipherPipeline& CipherPipeline::operator +=( vector<Cipher *> vc)
{
  for(int i = 0; i < vc.size(); ++i) {
    pipeline.push_back( vc[i] );
  }

  return *this;
}

CipherPipeline& CipherPipeline::operator =( vector<Cipher *> vc )
{
  pipeline.clear();
  pipeline = vc;

  return *this;
}
