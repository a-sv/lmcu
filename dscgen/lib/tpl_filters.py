# coding: utf-8
import re

def bool(val):
  try:
    val = int(val)
  except:
    val = None
  if not val:
    return 'false'
  return 'true'

def addr16(val):
  try:
    val = int(val)
  except:
    val = 0
  return '0x%0.4X' % (val)

def addr32(val):
  try:
    val = int(val)
  except:
    val = 0
  return '0x%0.8X' % (val)

def lower(val):
  if val is None:
    return None
  return val.lower()

def upper(val):
  if val is None:
    return None
  return val.upper()

def typesz(val):
  val = int(val)

  if val <= 8:
    return 'uint8_t'
  if val <= 16:
    return 'uint16_t'
  if val <= 32:
    return 'uint32_t'
  if val <= 64:
    return 'uint64_t'

  raise Exception("Invalid type size!")

def toint(val):
  if val == None:
    return 0
  if type(val) == int or type(val) == float:
    return int(val)
  val = str(val).strip()
  if not val:
    return 0
  pref = val[:2].upper()
  if pref == '0X':
    return int(val, 16)
  if pref == '0O':
    return int(val, 8)
  if pref == '0B':
    return int(val, 2)
  return int(val)

def comment(val):
  if val:
    return '// ' + re.sub(r'\ {2,}', "", str(val)).replace('\n', ' ')
  return ''
