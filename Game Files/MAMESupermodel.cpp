// Test wrapper for the Model 2 constant-torque FFB path.
// Load all normal dependencies before enabling the test macros so they only
// affect the MAMESupermodel implementation itself.
#include "MAMESupermodel.h"
#include <string>
#include <tchar.h>
#include <atlstr.h>
#include "SDL.h"
#include "../Common Files/SignatureScanning.h"

#include "M2ConstantPath.h"
#include "MAMESupermodel_base.inc"
