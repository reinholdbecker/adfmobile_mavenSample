(function(a){amx.registerRenderers("amx",{panelItem:{create:function(b){var d=document.createElement("div");d.setAttribute("title",this._ensureValidString(b.getAttribute("shortDesc"),""));a(d).append(b.renderSubNodes());adf.mf.internal.amx.addCSSClassName(d,"current");return d},_ensureValidString:function(a,d){return null==a?d:a}},panelSplitter:{createChildrenNodes:function(a){var d=a.getTag();if(void 0===a.getAttribute("selectedItem")&&d.isAttributeElBound("selectedItem"))return a.setState(adf.mf.api.amx.AmxNodeStates.INITIAL),
!0;var e=this._getSelectedTag(a),g=null==e?null:e.getAttribute("id");adf.mf.api.amx.setVolatileState(a.getAttribute("id"),{resolvedSelectedItemId:g});a.addChild(e.buildAmxNode(a,null));d=d.getChildFacetTag("navigator");if(null!=d){d=d.getChildrenUITags();for(i=0,size=d.length;i<size;++i)a.addChild(d[i].buildAmxNode(a,null),"navigator")}return!0},updateChildren:function(a,d){if(d.hasChanged("selectedItem")){var e=d.getSize(),g=adf.mf.api.amx.getVolatileState(a.getAttribute("id")).resolvedSelectedItemId;
if(a.getAttribute("selectedItem")!=g){if(g=a.getChildren(),0<g.length&&a.removeChild(g[0]),g=this._getSelectedTag(a),a.addChild(g.buildAmxNode(a,null)),adf.mf.api.amx.setVolatileState(a.getAttribute("id"),{resolvedSelectedItemId:g.getAttribute("id")}),1==e)return adf.mf.api.amx.AmxNodeChangeResult.REFRESH}else if(1==e)return adf.mf.api.amx.AmxNodeChangeResult.NONE}return adf.mf.api.amx.AmxNodeChangeResult.RERENDER},create:function(a){try{var d=this._getOrientation(),e=this._getPosition(a),g=document.createElement("div");
g.setAttribute("title",this._ensureValidString(a.getAttribute("shortDesc"),""));g.setAttribute("data-orientation",d);var h=document.createElement("div");h.className="amx-panelSplitter_inner";g.appendChild(h);var k=document.createElement("div");k.className="amx-panelSplitter_contentContainer amx-scrollable";h.appendChild(k);k.setAttribute("role","contentinfo");0<a.getRenderedChildren("navigator").length?(d="landscape"==d,this._createNavigation(d,a,h,g,e),d?(adf.mf.internal.amx.addCSSClassName(k,"amx-landscape"),
"rtl"==document.documentElement.dir?k.style.right=e.landscape:k.style.left=e.landscape):adf.mf.internal.amx.addCSSClassName(k,"amx-portrait")):adf.mf.internal.amx.addCSSClassName(k,"amx-noNavigation");var m=a.getRenderedChildren(),n=0<m.length?m[0]:null;if(null!=n){var o=n.renderNode();if(null!=o){var q=o.get(0);adf.mf.internal.amx.addCSSClassName(q,"current");k.appendChild(q)}}return g}catch(s){console.error(s)}},postDisplay:function(b,d){try{var e=this._getChildrenByClassNames(b.firstChild,["amx-panelSplitter_navLandscape",
"amx-panelSplitter_navPortrait","amx-panelSplitter_contentContainer"]),g=e[0],h=e[1],k=e[2],m=adf.mf.api.amx.getClientState(d.getId());null!=m&&(this._restoreScrollPositions(g,m.navLandscape),this._restoreScrollPositions(h,m.navPortrait),this._restoreScrollPositions(k,m.content));0<d.getChildren("navigator").length&&(e={rootElement:b,peer:this,amxNode:d},a(window).resize(e,this._handleResize),a(b).resize(e,this._handleResize))}catch(n){console.error(n)}},refresh:function(b){try{var d=b.getRenderedChildren();
if(0!=d.length){var e=document.getElementById(b.getId()),g=this._getChildrenByClassNames(e.firstChild,["amx-panelSplitter_contentContainer"])[0];adf.mf.internal.amx.getCSSClassNameIndex(e.className,"changingSelectedItem");adf.mf.internal.amx.addCSSClassName(e,"changingSelectedItem");var h=this._getChildrenByClassNames(g,["current"])[0],k=d[0],m=k.renderNode();if(null!=m){var n=m.get(0),o=null==n?null:n.getAttribute("id");adf.mf.api.amx.setVolatileState(b.getAttribute("id"),{resolvedSelectedItemId:o});
adf.mf.internal.amx.addCSSClassName(n,"new");g.appendChild(n);1==n.childNodes.length&&a(n.childNodes[0]).resize()}if("portrait"==e.getAttribute("data-orientation"))try{var q=this._getPosition(b);this._undiscloseNavPortrait(e,q)}catch(s){console.error(s)}var t=this._getChildrenByClassNames(g,["new"])[0],u=this._getTransitionParams(b,k),b=null;"slide"==u.type?(adf.mf.internal.amx.removeCSSClassName(t,"current"),b=this._slide(e,h,t,u.direction)):"flip"==u.type?(adf.mf.internal.amx.removeCSSClassName(t,
"current"),b=this._flip(e,h,t,u.direction)):(adf.mf.internal.amx.removeCSSClassName(t,"new"),adf.mf.internal.amx.addCSSClassName(t,"current"),this._removeAllButThisOrTheOnlyPanelItem(t,g),adf.mf.internal.amx.removeCSSClassName(e,"changingSelectedItem"));null!=b&&(adf.mf.internal.amx.pauseUIChanges(),b.always(function(){adf.mf.internal.amx.resumeUIChanges()}))}}catch(v){console.error(v)}},preDestroy:function(a,d){this._storeScrollPositions(a.jquery?a.get(0):nodeOrDomNode,d.getId())},_getSelectedTag:function(a){for(var d=
a.getTag(),a=a.getAttribute("selectedItem"),d=d.getChildren("http://xmlns.oracle.com/adf/mf/amx","panelItem"),e=null,g=0,h=d.length;g<h;++g){var k=d[g];if(null==a)return k;0==g&&(e=k);if(k.getAttribute("id")==a)return k}return e},_removeAllButThisOrTheOnlyPanelItem:function(b,d){for(var e=d.childNodes,g=e.length;0<=g&&1<d.childNodes.length;--g){var h=e[g];h!=b&&a(h).remove()}},_getChildrenByClassNames:function(a,d){for(var e=a.childNodes,g=e.length,h=d.length,k=[],m=0,n=0;n<g&&m<h;++n)for(var o=e[n],
q=0;q<h;++q)if(-1!=adf.mf.internal.amx.getCSSClassNameIndex(o.className,d[q])){k[q]=o;++m;break}return k},_storeScrollPositions:function(a,d){var e=this._getChildrenByClassNames(a.firstChild,["amx-panelSplitter_navLandscape","amx-panelSplitter_navPortrait","amx-panelSplitter_contentContainer"]),g=e[1],h=e[2],e={navLandscape:this._getScrollPositions(e[0]),navPortrait:this._getScrollPositions(g),content:this._getScrollPositions(h)};adf.mf.api.amx.setClientState(d,e)},_getScrollPositions:function(a){if(a){var d=
a.scrollLeft,a=a.scrollTop;if(null!=d&&null!=a)return{scrollLeft:d,scrollTop:a}}return null},_restoreScrollPositions:function(a,d){if(a&&d){var e=d.scrollLeft;null!=e&&(a.scrollLeft=e);e=d.scrollTop;null!=e&&(a.scrollTop=e)}},_getTransitionParams:function(a,d){var e="none",g=null;null!=d.getAttribute("animation")?e=d.getAttribute("animation"):null!=a.getAttribute("animation")&&(e=a.getAttribute("animation"));e=e.toLowerCase();switch(e){case "flipup":g={type:"flip",direction:"up"};break;case "flipdown":g=
{type:"flip",direction:"down"};break;case "flipleft":g={type:"flip",direction:"left"};break;case "flipright":g={type:"flip",direction:"right"};break;case "flipstart":g={type:"flip",direction:"start"};break;case "flipend":g={type:"flip",direction:"end"};break;case "slideup":g={type:"slide",direction:"up"};break;case "slidedown":g={type:"slide",direction:"down"};break;case "slideleft":g={type:"slide",direction:"left"};break;case "slideright":g={type:"slide",direction:"right"};break;case "slidestart":g=
{type:"slide",direction:"start"};break;case "slideend":g={type:"slide",direction:"end"};break;default:g={type:"none",direction:"start"}}return g},_slide:function(b,d,e,g){var h=!1,k=!1;if("up"==g||"down"==g)h=!0;var m="rtl"==document.documentElement.dir;if(m){if("left"==g||"end"==g||"down"==g)k=!0}else if("right"==g||"end"==g||"down"==g)k=!0;var n=a.Deferred(),o;h?(m=d.offsetHeight,k=k?-1*m:m,o=-1*k,d.style.height=m+"px",e.style.height=m+"px",e.style.top=k+"px"):(g=d.offsetWidth,k=k?-1*g:g,o=k*(m?
1:-1),d.style.width=g+"px",e.style.width=g+"px","rtl"==document.documentElement.dir?e.style.right=k+"px":e.style.left=k+"px");adf.mf.internal.amx.removeCSSClassName(e,"new");adf.mf.internal.amx.addCSSClassName(e,"showing");var q=this;setTimeout(function(){var g=a.Deferred(),k=a.Deferred();adf.mf.internal.amx.addCSSClassName(e,"transitioning");adf.mf.internal.amx.addCSSClassName(d,"transitioning");d.style.webkitTransform=h?"translate(0,"+o+"px)":"translate("+o+"px,0)";a(d).bind("webkitTransitionEnd",
function(){adf.mf.internal.amx.removeCSSClassName(d,"current");adf.mf.internal.amx.addCSSClassName(d,"old");adf.mf.internal.amx.removeCSSClassName(d,"transitioning");var a=q._getChildrenByClassNames(b.firstChild,["amx-panelSplitter_contentContainer"])[0];q._removeAllButThisOrTheOnlyPanelItem(e,a);g.resolve()});adf.mf.internal.amx.addCSSClassName(e,"transitioning");e.style.webkitTransform=h?"translate(0,"+o+"px)":"translate("+o+"px,0)";a(e).bind("webkitTransitionEnd",function(){adf.mf.internal.amx.removeCSSClassName(e,
"showing");adf.mf.internal.amx.addCSSClassName(e,"current");adf.mf.internal.amx.removeCSSClassName(e,"transitioning");e.setAttribute("style","");k.resolve()});a.when(g,k).done(function(){n.resolve();adf.mf.internal.amx.removeCSSClassName(b,"changingSelectedItem")})},1);return n.promise()},_flip:function(b,d,e,g){var h=!1,k=!1;if("up"==g||"down"==g)h=!0;if("rtl"==document.documentElement.dir){if("right"==g||"start"==g||"up"==g)k=!0}else if("right"==g||"end"==g||"up"==g)k=!0;var m=a.Deferred(),g=k?
"rotateY(-180deg)":"rotateY(180deg)";if(h)g=d.offsetHeight,d.style.height=g+"px",e.style.height=g+"px",g=k?"rotateX(-180deg)":"rotateX(180deg)",adf.mf.internal.amx.addCSSClassName(d,"face"),d.style.webkitTransform="rotateX(0deg)";else{var n=d.offsetWidth;d.style.width=n+"px";e.style.width=n+"px";adf.mf.internal.amx.addCSSClassName(d,"face");d.style.webkitTransform="rotateY(0deg)"}adf.mf.internal.amx.addCSSClassName(e,"face");e.style.webkitTransform=g;adf.mf.internal.amx.removeCSSClassName(e,"new");
adf.mf.internal.amx.addCSSClassName(e,"showing");var o=this;setTimeout(function(){var g=a.Deferred(),n=a.Deferred(),t=o._getChildrenByClassNames(b.firstChild,["amx-panelSplitter_contentContainer"])[0];adf.mf.internal.amx.addCSSClassName(t,"transitioning");adf.mf.internal.amx.addCSSClassName(d,"transitioning-slow");var u=k?"rotateY(+180deg)":"rotateY(-180deg)";h&&(u=k?"rotateX(+180deg)":"rotateX(-180deg)");d.style.webkitTransform=u;a(d).bind("webkitTransitionEnd",function(){adf.mf.internal.amx.removeCSSClassName(d,
"current");adf.mf.internal.amx.addCSSClassName(d,"old");adf.mf.internal.amx.removeCSSClassName(d,"transitioning-slow");adf.mf.internal.amx.removeCSSClassName(d,"face");o._removeAllButThisOrTheOnlyPanelItem(e,t);g.resolve()});adf.mf.internal.amx.addCSSClassName(e,"transitioning-slow");e.style.webkitTransform=h?"rotateX(0deg)":"rotateY(0deg)";a(e).bind("webkitTransitionEnd",function(){adf.mf.internal.amx.removeCSSClassName(e,"showing");adf.mf.internal.amx.addCSSClassName(e,"current");adf.mf.internal.amx.removeCSSClassName(e,
"transitioning-slow");adf.mf.internal.amx.removeCSSClassName(e,"face");adf.mf.internal.amx.removeCSSClassName(t,"transitioning");e.setAttribute("style","");n.resolve()});a.when(g,n).done(function(){m.resolve();adf.mf.internal.amx.removeCSSClassName(b,"changingSelectedItem")})},1);return m.promise()},_getAttribute:function(a,d){return null==a||""==a||adf.mf.environment.profile.dtMode&&"#"==a.charAt(0)?d:a},_getPosition:function(a){return{landscape:this._getAttribute(a.getAttribute("position"),"31.25%"),
portrait:"41.67%"}},_getOrientation:function(){return document.body.offsetWidth<document.body.offsetHeight?"portrait":"landscape"},_createNavigation:function(b,d,e,g,h){var k=document.createElement("div");k.className="amx-panelSplitter_navLandscape amx-scrollable";e.appendChild(k);k.style.width=h.landscape;k.setAttribute("role","navigation");var m=document.createElement("div");m.className="amx-panelSplitter_screenPortrait";e.appendChild(m);m.style.display="none";var n=document.createElement("div");
n.setAttribute("role","button");n.setAttribute("tabindex","0");n.setAttribute("aria-expanded","false");var o=adf.mf.resource.getInfoString("AMXInfoBundle","amx_panelSplitter_NAVIGATOR_TOGGLE_BUTTON"),o=this._ensureValidString(d.getAttribute("navigatorTitle"),o);n.setAttribute("title",o);n.className="amx-panelSplitter_button";e.appendChild(n);g={rootElement:g,amxNode:d,peer:this};a(m).tap(g,this._handleNavPortraitToggle);a(n).tap(g,this._handleNavPortraitToggle);m=document.createElement("div");g=d.getId()+
"::navp";m.setAttribute("id",g);n.setAttribute("aria-owns",g);m.setAttribute("aria-hidden","true");m.className="amx-panelSplitter_navPortrait amx-scrollable";e.appendChild(m);m.style.width=h.portrait;m.setAttribute("role","navigation");b?(m.style.opacity="0",m.style.display="none",m.style.zIndex="0",n.style.display="none"):(k.style.opacity="0",k.style.display="none","rtl"==document.documentElement.dir?m.style.right="-"+h.portrait:m.style.left="-"+h.portrait);b=b?k:m;d=d.getRenderedChildren("navigator");
e=0;for(h=d.length;e<h;++e)k=d[e].renderNode().get(0),b.appendChild(k)},_handleNavPortraitToggle:function(a){try{a.preventDefault();a.stopPropagation();var d=a.data.rootElement,e=a.data.peer,g=e._getPosition(a.data.amxNode),h=e._getChildrenByClassNames(d.firstChild,["amx-panelSplitter_button"])[0];-1!=adf.mf.internal.amx.getCSSClassNameIndex(h.className,"disclosed")?e._undiscloseNavPortrait(d,g):e._discloseNavPortrait(d,g)}catch(k){console.error(k)}},_discloseNavPortrait:function(a,d){var e=this._getChildrenByClassNames(a.firstChild,
["amx-panelSplitter_screenPortrait","amx-panelSplitter_navPortrait","amx-panelSplitter_button","amx-panelSplitter_contentContainer"]),g=e[0],h=e[1],k=e[2],e=e[3];g&&h&&k&&(g.style.display="block",adf.mf.internal.amx.addCSSClassName(h,"no-animate"),h.style.opacity="1",h.style.display="block",h.style.zIndex="1002",adf.mf.internal.amx.removeCSSClassName(h,"no-animate"),(g="rtl"==document.documentElement.dir)?h.style.right="0px":h.style.left="0px",g?k.style.right=d.portrait:k.style.left=d.portrait,adf.mf.internal.amx.addCSSClassName(k,
"disclosed"),h.setAttribute("aria-hidden","false"),k.setAttribute("aria-expanded","true"),e.setAttribute("aria-hidden","true"))},_undiscloseNavPortrait:function(a,d){var e=this._getChildrenByClassNames(a.firstChild,["amx-panelSplitter_screenPortrait","amx-panelSplitter_navPortrait","amx-panelSplitter_button","amx-panelSplitter_contentContainer"]),g=e[0],h=e[1],k=e[2],e=e[3];g&&h&&k&&(g.style.display="none",(g="rtl"==document.documentElement.dir)?h.style.right="-"+d.portrait:h.style.left="-"+d.portrait,
g?k.style.right="0px":k.style.left="0px",adf.mf.internal.amx.removeCSSClassName(k,"disclosed"),h.setAttribute("aria-hidden","true"),k.setAttribute("aria-expanded","false"),e.setAttribute("aria-hidden","false"))},_ensureValidString:function(a,d){return null==a?d:a},_handleResize:function(b){var d=b.data.rootElement,e=b.data.amxNode,g=b.data.peer,h=g._getChildrenByClassNames(d.firstChild,["amx-panelSplitter_navPortrait","amx-panelSplitter_button","amx-panelSplitter_screenPortrait","amx-panelSplitter_navLandscape",
"amx-panelSplitter_contentContainer"]),b=h[0],k=h[1],m=h[2],n=h[3],h=h[4],o=g._getOrientation(),e=g._getPosition(e),g="rtl"==document.documentElement.dir;b&&k&&m&&n&&"portrait"==d.getAttribute("data-orientation")&&"landscape"==o?(adf.mf.internal.amx.addCSSClassName(b,"no-animate"),g?b.style.right="-"+e.portrait:b.style.left="-"+e.portrait,b.style.opacity="0",b.style.display="none",b.style.zIndex="0",adf.mf.internal.amx.removeCSSClassName(b,"no-animate"),adf.mf.internal.amx.addCSSClassName(k,"no-animate"),
g?k.style.right="0px":k.style.left="0px",k.style.display="none",adf.mf.internal.amx.removeCSSClassName(k,"no-animate"),adf.mf.internal.amx.removeCSSClassName(k,"disclosed"),m.style.display="none",a(b).children().appendTo(a(n)),n.style.opacity="1",n.style.display="block",g?h.style.right=e.landscape:h.style.left=e.landscape,d.setAttribute("data-orientation","landscape"),adf.mf.internal.amx.removeCSSClassName(h,"amx-portrait"),adf.mf.internal.amx.addCSSClassName(h,"amx-landscape"),h.setAttribute("aria-hidden",
"false")):"landscape"==d.getAttribute("data-orientation")&&"portrait"==o&&(g?b.style.right="-"+e.portrait:b.style.left="-"+e.portrait,b.style.zIndex="1002",g?k.style.right="0px":k.style.left="0px",n.style.opacity="0",n.style.display="none",k.style.display="block",g?h.style.right="":h.style.left="",a(n).children().appendTo(a(b)),d.setAttribute("data-orientation","portrait"),adf.mf.internal.amx.removeCSSClassName(h,"amx-landscape"),adf.mf.internal.amx.addCSSClassName(h,"amx-portrait"),b.setAttribute("aria-hidden",
"true"),k.setAttribute("aria-expanded","false"),h.setAttribute("aria-hidden","false"))}}})})(jQuery);