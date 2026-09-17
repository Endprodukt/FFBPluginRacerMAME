// Test wrapper for the Model 2 constant-torque FFB path.
// Load the normal dependencies before enabling the test macros so they only
// affect the MAMESupermodel implementation itself. SignatureScanning.h stays
// inside MAMESupermodel_base.inc because it has no include guard.
#include "MAMESupermodel.h"
#include <string>
#include <tchar.h>
#include <atlstr.h>
#include "SDL.h"

#include "M2ConstantPath.h"
#include "MAMESupermodel_base.inc"
