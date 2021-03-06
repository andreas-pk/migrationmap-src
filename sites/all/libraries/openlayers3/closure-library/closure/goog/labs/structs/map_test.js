// Copyright 2012 The Closure Library Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS-IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

goog.provide('goog.labs.structs.MapTest');
goog.setTestOnly('goog.labs.structs.MapTest');

goog.require('goog.labs.structs.Map');
goog.require('goog.testing.PropertyReplacer');
goog.require('goog.testing.jsunit');

var map;
var stubs;

function setUpPage() {
  stubs = new goog.testing.PropertyReplacer();
}

function setUp() {
  map = new goog.labs.structs.Map();
}


function testSet() {
  var key = 'test';
  var value = 'value';
  map.set(key, value);
  assertEquals(value, map.get(key));
}


function testSetsWithSameKey() {
  var key = 'test';
  var value = 'value';
  var value2 = 'value2';
  map.set(key, value);
  map.set(key, value2);
  assertEquals(value2, map.get(key));
}


function testSetWithUndefinedValue() {
  var key = 'test';
  map.set(key, undefined);
  assertUndefined(map.get(key));
}


function testSetWithUnderUnderProtoUnderUnder() {
  var key = '__proto__';
  var value = 'value';
  var value2 = 'value2';

  map.set(key, value);
  assertEquals(value, map.get(key));

  map.set(key, value2);
  assertEquals(value2, map.get(key));
}


function testSetWithBuiltInPropertyShadows() {
  var key = 'toString';
  var value = 'value';
  var key2 = 'hasOwnProperty';
  var value2 = 'value2';

  map.set(key, value);
  map.set(key2, value2);
  assertEquals(value, map.get(key));
  assertEquals(value2, map.get(key2));

  map.set(key, value2);
  map.set(key2, value);
  assertEquals(value2, map.get(key));
  assertEquals(value, map.get(key2));
}


function testGetBeforeSetOfUnderUnderProtoUnderUnder() {
  assertUndefined(map.get('__proto__'));
}


function testContainsKey() {
  assertFalse(map.containsKey('key'));
  assertFalse(map.containsKey('__proto__'));
  assertFalse(map.containsKey('toString'));
  assertFalse(map.containsKey('hasOwnProperty'));
  assertFalse(map.containsKey('key2'));
  assertFalse(map.containsKey('key3'));
  assertFalse(map.containsKey('key4'));

  map.set('key', 'v');
  map.set('__proto__', 'v');
  map.set('toString', 'v');
  map.set('hasOwnProperty', 'v');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('key4', '');

  assertTrue(map.containsKey('key'));
  assertTrue(map.containsKey('__proto__'));
  assertTrue(map.containsKey('toString'));
  assertTrue(map.containsKey('hasOwnProperty'));
  assertTrue(map.containsKey('key2'));
  assertTrue(map.containsKey('key3'));
  assertTrue(map.containsKey('key4'));
}


function testContainsValueWithShadowKeys() {
  assertFalse(map.containsValue('v2'));
  assertFalse(map.containsValue('v3'));
  assertFalse(map.containsValue('v4'));

  map.set('__proto__', 'v2');
  map.set('toString', 'v3');
  map.set('hasOwnProperty', 'v4');

  assertTrue(map.containsValue('v2'));
  assertTrue(map.containsValue('v3'));
  assertTrue(map.containsValue('v4'));

  assertFalse(map.containsValue(Object.prototype.toString));
  assertFalse(map.containsValue(Object.prototype.hasOwnProperty));
}


function testContainsValueWithNullAndUndefined() {
  assertFalse(map.containsValue(undefined));
  assertFalse(map.containsValue(null));

  map.set('key2', undefined);
  map.set('key3', null);

  assertTrue(map.containsValue(undefined));
  assertTrue(map.containsValue(null));
}


function testContainsValueWithNumber() {
  assertFalse(map.containsValue(-1));
  assertFalse(map.containsValue(0));
  assertFalse(map.containsValue(1));
  map.set('key', -1);
  map.set('key2', 0);
  map.set('key3', 1);
  assertTrue(map.containsValue(-1));
  assertTrue(map.containsValue(0));
  assertTrue(map.containsValue(1));
}


function testContainsValueWithNaN() {
  assertFalse(map.containsValue(NaN));
  map.set('key', NaN);
  assertTrue(map.containsValue(NaN));
}


function testContainsValueWithNegativeZero() {
  assertFalse(map.containsValue(-0));
  map.set('key', -0);
  assertTrue(map.containsValue(-0));
  assertFalse(map.containsValue(0));

  map.set('key', 0);
  assertFalse(map.containsValue(-0));
  assertTrue(map.containsValue(0));
}


function testContainsValueWithStrings() {
  assertFalse(map.containsValue(''));
  assertFalse(map.containsValue('v'));
  map.set('key', '');
  map.set('key2', 'v');
  assertTrue(map.containsValue(''));
  assertTrue(map.containsValue('v'));
}

function testRemove() {
  map.set('key', 'v');
  map.set('__proto__', 'v2');
  map.set('toString', 'v3');
  map.set('hasOwnProperty', 'v4');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('key4', '');

  assertFalse(map.remove('key do not exist'));

  assertTrue(map.remove('key'));
  assertFalse(map.containsKey('key'));
  assertFalse(map.remove('key'));

  assertTrue(map.remove('__proto__'));
  assertFalse(map.containsKey('__proto__'));
  assertFalse(map.remove('__proto__'));

  assertTrue(map.remove('toString'));
  assertFalse(map.containsKey('toString'));
  assertFalse(map.remove('toString'));

  assertTrue(map.remove('hasOwnProperty'));
  assertFalse(map.containsKey('hasOwnProperty'));
  assertFalse(map.remove('hasOwnProperty'));

  assertTrue(map.remove('key2'));
  assertFalse(map.containsKey('key2'));
  assertFalse(map.remove('key2'));

  assertTrue(map.remove('key3'));
  assertFalse(map.containsKey('key3'));
  assertFalse(map.remove('key3'));

  assertTrue('', map.remove('key4'));
  assertFalse(map.containsKey('key4'));
  assertFalse(map.remove('key4'));
}


function testGetCountAndIsEmpty() {
  assertEquals(0, map.getCount());
  assertTrue(map.isEmpty());

  map.set('key', 'v');
  assertEquals(1, map.getCount());
  map.set('__proto__', 'v2');
  assertEquals(2, map.getCount());
  map.set('toString', 'v3');
  assertEquals(3, map.getCount());
  map.set('hasOwnProperty', 'v4');
  assertEquals(4, map.getCount());

  map.set('key', 'a');
  assertEquals(4, map.getCount());
  map.set('__proto__', 'a2');
  assertEquals(4, map.getCount());
  map.set('toString', 'a3');
  assertEquals(4, map.getCount());
  map.set('hasOwnProperty', 'a4');
  assertEquals(4, map.getCount());

  map.remove('key');
  assertEquals(3, map.getCount());
  map.remove('__proto__');
  assertEquals(2, map.getCount());
  map.remove('toString');
  assertEquals(1, map.getCount());
  map.remove('hasOwnProperty');
  assertEquals(0, map.getCount());
}


function testClear() {
  map.set('key', 'v');
  map.set('__proto__', 'v');
  map.set('toString', 'v');
  map.set('hasOwnProperty', 'v');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('key4', '');

  map.clear();

  assertFalse(map.containsKey('key'));
  assertFalse(map.containsKey('__proto__'));
  assertFalse(map.containsKey('toString'));
  assertFalse(map.containsKey('hasOwnProperty'));
  assertFalse(map.containsKey('key2'));
  assertFalse(map.containsKey('key3'));
  assertFalse(map.containsKey('key4'));
}


function testGetEntries() {
  map.set('key', 'v');
  map.set('__proto__', 'v');
  map.set('toString', 'v');
  map.set('hasOwnProperty', 'v');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('key4', '');

  var entries = map.getEntries();
  assertEquals(7, entries.length);
  assertContainsEntry(['key', 'v'], entries);
  assertContainsEntry(['__proto__', 'v'], entries);
  assertContainsEntry(['toString', 'v'], entries);
  assertContainsEntry(['hasOwnProperty', 'v'], entries);
  assertContainsEntry(['key2', undefined], entries);
  assertContainsEntry(['key3', null], entries);
  assertContainsEntry(['key4', ''], entries);
}


function testGetKeys() {
  map.set('key', 'v');
  map.set('__proto__', 'v');
  map.set('toString', 'v');
  map.set('hasOwnProperty', 'v');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('k4', '');

  var values = map.getKeys();
  assertSameElements(
      ['key', '__proto__', 'toString', 'hasOwnProperty', 'key2', 'key3', 'k4'],
      values);
}


function testGetValues() {
  map.set('key', 'v');
  map.set('__proto__', 'v');
  map.set('toString', 'v');
  map.set('hasOwnProperty', 'v');
  map.set('key2', undefined);
  map.set('key3', null);
  map.set('key4', '');

  var values = map.getValues();
  assertSameElements(['v', 'v', 'v', 'v', undefined, null, ''], values);
}


function testAddAllToEmptyMap() {
  map.set('key', 'v');
  map.set('key2', 'v2');
  map.set('key3', 'v3');
  map.set('key4', 'v4');

  var map2 = new goog.labs.structs.Map();
  map2.addAll(map);

  assertEquals(4, map2.getCount());
  assertEquals('v', map2.get('key'));
  assertEquals('v2', map2.get('key2'));
  assertEquals('v3', map2.get('key3'));
  assertEquals('v4', map2.get('key4'));
}


function testAddAllToNonEmptyMap() {
  map.set('key', 'v');
  map.set('key2', 'v2');
  map.set('key3', 'v3');
  map.set('key4', 'v4');

  var map2 = new goog.labs.structs.Map();
  map2.set('key0', 'o');
  map2.set('key', 'o');
  map2.set('key2', 'o2');
  map2.set('key3', 'o3');
  map2.addAll(map);

  assertEquals(5, map2.getCount());
  assertEquals('o', map2.get('key0'));
  assertEquals('v', map2.get('key'));
  assertEquals('v2', map2.get('key2'));
  assertEquals('v3', map2.get('key3'));
  assertEquals('v4', map2.get('key4'));
}


function testClone() {
  map.set('key', 'v');
  map.set('key2', 'v2');
  map.set('key3', 'v3');
  map.set('key4', 'v4');

  var map2 = map.clone();

  assertEquals(4, map2.getCount());
  assertEquals('v', map2.get('key'));
  assertEquals('v2', map2.get('key2'));
  assertEquals('v3', map2.get('key3'));
  assertEquals('v4', map2.get('key4'));
}


function testMapWithModifiedObjectPrototype() {
  stubs.set(Object.prototype, 'toString', function() {});
  stubs.set(Object.prototype, 'foo', function() {});
  stubs.set(Object.prototype, 'field', 100);
  stubs.set(Object.prototype, 'fooKey', function() {});

  map = new goog.labs.structs.Map();
  map.set('key', 'v');
  map.set('key2', 'v2');
  map.set('fooKey', 'v3');

  assertTrue(map.containsKey('key'));
  assertTrue(map.containsKey('key2'));
  assertTrue(map.containsKey('fooKey'));
  assertFalse(map.containsKey('toString'));
  assertFalse(map.containsKey('foo'));
  assertFalse(map.containsKey('field'));

  assertTrue(map.containsValue('v'));
  assertTrue(map.containsValue('v2'));
  assertTrue(map.containsValue('v3'));
  assertFalse(map.containsValue(100));

  var entries = map.getEntries();
  assertEquals(3, entries.length);
  assertContainsEntry(['key', 'v'], entries);
  assertContainsEntry(['key2', 'v2'], entries);
  assertContainsEntry(['fooKey', 'v3'], entries);
}


function assertContainsEntry(entry, entryList) {
  for (var i = 0; i < entryList.length; ++i) {
    if (entry[0] == entryList[i][0] && entry[1] === entryList[i][1]) {
      return;
    }
  }
  fail('Did not find entry: ' + entry + ' in: ' + entryList);
}
