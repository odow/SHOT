//=============================================================================
/*! zrovector*_zcovector operator */
inline comple operator*(const zrovector& rovec, const _zcovector& covec)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(rovec.l!=covec.l){
    ERROR_REPORT;
    std::cerr << "These two vectors can not make a product." << std::endl
              << "Your input was (" << rovec.l << ") * (" << covec.l << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  comple val( zdotu_( rovec.l, rovec.array, 1, covec.array, 1 ) );
  
  covec.destroy();
  return val;
}
