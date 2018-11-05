#include "floatarray.h"

 FloatArray::FloatArray( ) : data( nullptr ), size( 0 ) {}

 FloatArray::FloatArray( float* d, int s ) : data( d ), size( s ) {}

void FloatArray::getMin( float* value, int* index ) {
  *value=data[0];
  *index=0;
  for(int n=1; n<size; n++){
    float currentValue=data[n];
    if(currentValue<*value){
      *value=currentValue;
      *index=n;
    }
  }
}

float FloatArray::getMinValue(){
  float value;
  int index;
  getMin(&value, &index);
  return value;
}

int FloatArray::getMinIndex(){
  float value;
  int index;
  getMin(&value, &index);
  return index;
}

void FloatArray::getMax(float* value, int* index){
  *value=data[0];
  *index=0;
  for(int n=1; n<size; n++){
    float currentValue=data[n];
    if(currentValue>*value){
      *value=currentValue;
      *index=n;
    }
  }
}

float FloatArray::getMaxValue(){
  float value;
  int index;
  getMax(&value, &index);
  return value;
}

int FloatArray::getMaxIndex(){
  float value;
  int index;
  getMax(&value, &index);
  return index;
}

void FloatArray::rectify(FloatArray& destination) {
  int minSize= std::min(size,destination.getSize());
  for(int n=0; n<minSize; n++){
    destination[n] = abs(data[n]);
  }
}

void FloatArray::rectify(){//in place
  rectify(*this);
}

void FloatArray::reverse(FloatArray& destination){ //this is actually "copy data with reverse"
  if(destination==*this){ //make sure it is not called "in-place"
    reverse();
    return;
  }
  for(int n=0; n<size; n++){
    destination[n]=data[size-n-1];
  }
}

void FloatArray::reverse(){//in place
  for(int n=0; n<size/2; n++){
    float temp=data[n];
    data[n]=data[size-n-1];
    data[size-n-1]=temp;
  }
}

void FloatArray::reciprocal(FloatArray& destination){
  float* data = getData();
  for(int n=0; n<getSize(); n++)
    destination[n] = 1.0f/data[n];
}

void FloatArray::reciprocal(){//in place
  reciprocal(*this);
}

float FloatArray::getRms(){
  float result;
  result=0;
  float *pSrc= data;
  for(int n=0; n<size; n++){
    result += pSrc[n]*pSrc[n];
  }
  result=sqrtf(result/size);
  return result;
}

float FloatArray::getMean(){
  float result;
  for(int n=0; n<size; n++){
    result+=data[n];
  }
  result=result/size;
  return result;
}

float FloatArray::getPower(){
  float result;
  result=0;
  float *pSrc = data;
  for(int n=0; n<size; n++){
    result += pSrc[n]*pSrc[n];
  }
  return result;
}

float FloatArray::getStandardDeviation(){
  float result;
  result=sqrtf(getVariance());
  return result;
}

float FloatArray::getVariance(){
  float result;
  float sumOfSquares=getPower();
  float sum=0;
  for(int n=0; n<size; n++){
    sum+=data[n];
  }
  result=(sumOfSquares - sum*sum/size) / (size - 1);
  return result;
}

void FloatArray::clip(){
  clip(1);
}

void FloatArray::clip(float max){
  for(int n=0; n<size; n++){
    if(data[n]>max)
      data[n]=max;
    else if(data[n]<-max)
      data[n]=-max;
  }
}

void FloatArray::clip(float min, float max){
  for(int n=0; n<size; n++){
    if(data[n]>max)
      data[n]=max;
    else if(data[n]<min)
      data[n]=min;
  }
}

FloatArray FloatArray::subArray(int offset, int length){
  if ( size >= offset+length )
      return FloatArray( data + offset, length );
}

void FloatArray::copyTo(FloatArray destination){
  copyTo(destination, std::min(size, destination.getSize()));
}

void FloatArray::copyFrom(FloatArray source){
  copyFrom(source, std::min(size, source.getSize()));
}

void FloatArray::copyTo(float* other, int length){
  if ( size >= length )
      memcpy((void *)other, (void *)getData(), length*sizeof(float));
}

void FloatArray::copyFrom(float* other, int length){
  if ( size >= length )
      memcpy((void *)getData(), (void *)other, length*sizeof(float));
}

void FloatArray::insert(FloatArray source, int sourceOffset, int destinationOffset, int samples){
  if ( size >= destinationOffset+samples )
      if ( source.size >= sourceOffset+samples )
          memcpy((void*)(getData()+destinationOffset), (void*)(source.getData()+sourceOffset), samples*sizeof(float));
}

void FloatArray::insert(FloatArray source, int destinationOffset, int samples){
  insert(source, 0, destinationOffset, samples);
}

void FloatArray::move(int fromIndex, int toIndex, int samples){
  if ( size >= toIndex+samples )
      memmove(data+toIndex, data+fromIndex, samples*sizeof(float)); //TODO: evaluate if it is appropriate to use arm_copy_f32 for this method
}

void FloatArray::setAll(float value){
  for(int n=0; n<size; n++){
    data[n]=value;
  }
}

void FloatArray::add(FloatArray operand2, FloatArray destination){ //allows in-place
  if ( operand2.size >= size &&  destination.size<=size )
      for( int n=0; n<size; n++ ) {
        destination[n] = data[n] + operand2[n];
      }
}

void FloatArray::add(FloatArray operand2){ //in-place
  add(operand2, *this);
}

void FloatArray::add(float scalar){
  for(int n=0; n<size; n++){
    data[n]+=scalar;
  }
}

void FloatArray::subtract(FloatArray operand2, FloatArray destination){ //allows in-place
  if ( operand2.size == size && destination.size >= size )
      for(int n=0; n<size; n++){
        destination[n]=data[n]-operand2[n];
      }
}

void FloatArray::subtract(FloatArray operand2){ //in-place
  subtract(operand2, *this);
}

void FloatArray::subtract(float scalar){
  for(int n=0; n<size; n++){
    data[n]-=scalar;
  }
}

void FloatArray::multiply(FloatArray operand2, FloatArray destination){ //allows in-place
  if ( operand2.size == size &&  destination.size==size )
  for(int n=0; n<size; n++){
    destination[n]=data[n]*operand2[n];
  }
}

void FloatArray::multiply(FloatArray operand2){ //in-place
  multiply(operand2, *this);
}

void FloatArray::multiply(float scalar){
  for(int n=0; n<size; n++)
    data[n]*=scalar;
}

void FloatArray::multiply(float scalar, FloatArray destination){
  for(int n=0; n<size; n++)
    destination[n] = data[n] * scalar;
}

void FloatArray::negate(FloatArray& destination){//allows in-place
  for(int n=0; n<size; n++){
    destination[n]=-data[n];
  }
}

void FloatArray::negate(){
  negate(*this);
}

void FloatArray::noise(){
  noise(-1, 1);
}

void FloatArray::noise(float min, float max){
  float amplitude = fabs(max-min);
  float offset = min;
  if ( getSize()>10 )
      if ( size == getSize( ) )
          for(int n=0; n<size; n++){
            data[n]=(rand()/(RAND_MAX+1.0f)) * amplitude + offset;
          }
}

void FloatArray::convolve(FloatArray operand2, FloatArray destination){
    if ( destination.size >= size + operand2.size -1 ) {
        int size2=operand2.getSize();
        for (int n=0; n<size+size2-1; n++){
            int n1=n;
            destination[n] =0;
            for(int k=0; k<size2; k++){
                if(n1>=0 && n1<size)
                destination[n]+=data[n1]*operand2[k];
                n1--;
            }
        }
    }
}

void FloatArray::convolve(FloatArray operand2, FloatArray destination, int offset, int samples){
  if ( destination.size >= size + operand2.size -1 ) {
      int size2=operand2.getSize();
      for (int n=offset; n<offset+samples; n++){
        int n1=n;
        destination[n] =0; //this should be [n-offset]
        for(int k=0; k<size2; k++){
          if(n1>=0 && n1<size)
            destination[n]+=data[n1]*operand2[k];//this should be destination[n-offset]
          n1--;
        }
      }
  }
}

void FloatArray::correlate(FloatArray operand2, FloatArray destination){
  destination.setAll(0);
  correlateInitialized(operand2, destination);
}

void FloatArray::correlateInitialized(FloatArray operand2, FloatArray destination){
  if ( destination.size >= size+operand2.size-1 ) {
      //correlation is the same as a convolution where one of the signals is flipped in time
      //so we flip in time operand2
      operand2.reverse();
      //and convolve it with fa to obtain the correlation
      convolve(operand2, destination);
      //and we flip back operand2, so that the input is not modified
      operand2.reverse();
  }
}

FloatArray FloatArray::create(int size){
  FloatArray fa(new float[size], size);
  fa.clear();
  return fa;
}

void FloatArray::destroy(FloatArray array){
  delete array.data;
}
