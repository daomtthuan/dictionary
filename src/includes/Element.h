#ifndef _ELEMENT_INCLUDE_
#define _ELEMENT_INCLUDE_

#include "./Word.h"

//--------------------------------------------------

// Element type
typedef Word Element;

//--------------------------------------------------

/**
 * Get Key of Element
 *
 * @param element - Getted Element
 *
 * @return - Key of Element
 */
String Element_GetKey(const Element element)
{
  return element->english;
}

#endif
