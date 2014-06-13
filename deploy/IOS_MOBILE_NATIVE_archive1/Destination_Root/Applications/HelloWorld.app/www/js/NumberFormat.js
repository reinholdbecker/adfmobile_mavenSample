window.TrNumberFormat=function(a,b){a||alert("type for TrNumberFormat not defined!");this._type=a;this._localeSymbols=getLocaleSymbols(b);this._pPre=this._localeSymbols.getPositivePrefix();this._pSuf=this._localeSymbols.getPositiveSuffix();this._nPre=this._localeSymbols.getNegativePrefix();this._nSuf=this._localeSymbols.getNegativeSuffix();this._maxFractionDigits=3;this._maxIntegerDigits=40;this._minFractionDigits="currency"==this._type?2:0;this._minIntegerDigits=1;this._groupingUsed=!0};
TrNumberFormat.getNumberInstance=function(a){return new TrNumberFormat("number",a)};TrNumberFormat.getCurrencyInstance=function(a){return new TrNumberFormat("currency",a)};TrNumberFormat.getPercentInstance=function(a){return new TrNumberFormat("percent",a)};TrNumberFormat.prototype.setGroupingUsed=function(a){this._groupingUsed=a};TrNumberFormat.prototype.isGroupingUsed=function(){return this._groupingUsed};
TrNumberFormat.prototype.setMaximumIntegerDigits=function(a){a&&(this._maxIntegerDigits=0>a?0:a,this._minIntegerDigits>this._maxIntegerDigits&&(this._minIntegerDigits=this._maxIntegerDigits))};TrNumberFormat.prototype.getMaximumIntegerDigits=function(){return this._maxIntegerDigits};
TrNumberFormat.prototype.setMaximumFractionDigits=function(a){a&&(this._maxFractionDigits=0>a?0:a,this._maxFractionDigits<this._minFractionDigits&&(this._minFractionDigits=this._maxFractionDigits),this._isMaxFractionDigitsSet=!0)};TrNumberFormat.prototype.getMaximumFractionDigits=function(){return this._maxFractionDigits};TrNumberFormat.prototype.setMinimumIntegerDigits=function(a){a&&(this._minIntegerDigits=0>a?0:a,this._minIntegerDigits>this._maxIntegerDigits&&(this._maxIntegerDigits=this._minIntegerDigits))};
TrNumberFormat.prototype.getMinimumIntegerDigits=function(){return this._minIntegerDigits};TrNumberFormat.prototype.setMinimumFractionDigits=function(a){a&&(this._minFractionDigits=0>a?0:a,this._maxFractionDigits<this._minFractionDigits&&(this._maxFractionDigits=this._minFractionDigits))};TrNumberFormat.prototype.getMinimumFractionDigits=function(){return this._minFractionDigits};
TrNumberFormat.prototype.format=function(a){if("percent"==this._type)return this.percentageToString(a);if("currency"==this._type)return this.currencyToString(a);if("number"==this._type)return this.numberToString(a)};TrNumberFormat.prototype.parse=function(a){return"percent"==this._type?this.stringToPercentage(a):"currency"==this._type?this.stringToCurrency(a):this.stringToNumber(a)};
TrNumberFormat.prototype.stringToNumber=function(a){if(isNaN(a)||-1!=a.indexOf("e")||-1!=a.indexOf("E"))throw new TrParseException("not able to parse number");return parseFloat(a)};
TrNumberFormat.prototype.stringToCurrency=function(a){var b=a.indexOf(this._nPre),d=this._nSuf;if(" "==d.charAt(0)||"\u00a0"==d.charAt(0))d=d.substring(1);var e=a.indexOf(d);if(-1!=b&&-1!=e)return a=a.substr(this._nPre.length,a.length-(this._nPre.length+d.length)),-1*this.stringToNumber(a);b=a.indexOf(this._pPre);d=this._pSuf;if(" "==d.charAt(0)||"\u00a0"==d.charAt(0))d=d.substring(1);e=a.indexOf(d);if(-1!=b&&-1!=e)return a=a.substr(this._pPre.length,a.length-(this._pPre.length+d.length)),a=this.stringToNumber(a);
throw new TrParseException("not able to parse number");};TrNumberFormat.prototype.stringToPercentage=function(a){if(-1==a.indexOf("%"))throw new TrParseException("not able to parse number");return this.stringToNumber(a.replace(/\%/g,""))};
TrNumberFormat.prototype.numberToString=function(a){var b=0>a;b&&(a*=-1);var d;d=TrNumberFormat.scientificToExpanded(a+"");var e=d.indexOf("."),g=d.length;-1!=e?(a=d.substring(0,e),d=d.substring(e+1,g)):(a=d,d="");a=this._formatIntegers(a);d=this._formatFractions(d);e=this._localeSymbols.getDecimalSeparator();d=""!=d?a+e+d:a;b&&(d="-"+d);return d};
TrNumberFormat.prototype.currencyToString=function(a){if(0>a)return a=this.numberToString(-1*a+""),this._nPre+a+this._nSuf;a=this.numberToString(a);return this._pPre+a+this._pSuf};
TrNumberFormat.prototype.percentageToString=function(a){a*=100;null==this._isMaxFractionDigitsSet?a=this.getRounded(a):null!=this._maxFractionDigits&&(a=this.getRoundedFixedDigits(a,this._maxFractionDigits));if(isNaN(a))throw new TrParseException("not able to parse number");var b=this._localeSymbols.getPercentSuffix();if(!b||""==b)throw new TrParseException("percent suffix undefined or empty");a=this.numberToString(a);return a+b};
TrNumberFormat.scientificToExpanded=function(a){var b=a.indexOf("e");if(-1==b)return a;var d="";"-"==a.charAt(0)&&(d="-",a=a.substring(1),b-=1);var e="+"==a.charAt(b+1),g=parseInt(a.substring(b+2)),h=b-2,k="";if(e){for(e=0;e<g-h;++e)k+="0";return d+a.charAt(0)+a.substring(2,b)+k}for(e=0;e<g-1;++e)k+="0";return d+"0."+k+a.charAt(0)+a.substring(2,b)};
TrNumberFormat.trimLeadingZeroes=function(a){var b=[],d,e;for(d=0;d<a.length;++d){e=a.charAt(d);if("1"<=e&&"9">=e||"."==e)break;"0"==e&&d+1<a.length&&"."!=a.charAt(d+1)||b.push(e)}return b.join("")+a.substring(d)};TrNumberFormat.prototype.getRoundedFixedDigits=function(a,b){return Math.round(a*Math.pow(10,b))/Math.pow(10,b)};TrNumberFormat.prototype.getRounded=function(a){a=this.moveDecimalRight(a);a=Math.round(a);return a=this.moveDecimalLeft(a)};
TrNumberFormat.prototype.moveDecimalRight=function(a){var b="";return b=this.moveDecimal(a,!1)};TrNumberFormat.prototype.moveDecimalLeft=function(a){var b="";return b=this.moveDecimal(a,!0)};TrNumberFormat.prototype.moveDecimal=function(a,b){var d="",d=this.moveDecimalAsString(a,b);return parseFloat(d)};
TrNumberFormat.prototype.moveDecimalAsString=function(a,b){var d=a+"",e=this.getZeros(2),g=/([0-9.]+)/;b?(d=d.replace(g,e+"$1"),e=/(-?)([0-9]*)([0-9]{2})(\.?)/,d=d.replace(e,"$1$2.$3")):(g=g.exec(d),null!=g&&(d=d.substring(0,g.index)+g[1]+e+d.substring(g.index+g[0].length)),e=/(-?)([0-9]*)(\.?)([0-9]{2})/,d=d.replace(e,"$1$2$4."));return d=d.replace(/\.$/,"")};TrNumberFormat.prototype.getZeros=function(a){var b="",d;for(d=0;d<a;d++)b+="0";return b};
TrNumberFormat.prototype._formatIntegers=function(a){var b=a.length,d=this.getMaximumIntegerDigits(),e=this.getMinimumIntegerDigits();if(b>d)a=a.substring(b-d,b);else if(b<e){b=e-b;for(d="";0<b;)d="0"+d,--b;a=d+a}this.isGroupingUsed()&&(a=this._addGroupingSeparators(a));return a};TrNumberFormat.prototype._formatFractions=function(a){var b=a.length,d=this.getMaximumFractionDigits(),e=this.getMinimumFractionDigits();b>d&&d>=e&&(a=a.substring(0,d));if(b<e)for(b=e-b;0<b;)a+="0",--b;return a};
TrNumberFormat.prototype._addGroupingSeparators=function(a){var b=a.length,d=b%3,e,g="",h=this._localeSymbols.getGroupingSeparator();0<d?(e=4>b?a.substring(0,d):a.substring(0,d)+h,a=a.substring(d,b)):e="";for(i=0;i<a.length;i++)0==i%3&&0!=i&&(g+=h),g+=a.charAt(i);return e+g};window.TrParseException=function(a){this._message=a};TrParseException.prototype.getMessage=function(){return this._message};