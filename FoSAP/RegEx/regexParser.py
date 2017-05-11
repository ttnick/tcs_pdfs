# Generated from regex.g4 by ANTLR 4.5.3
# encoding: utf-8
from __future__ import print_function
from antlr4 import *
from io import StringIO

def serializedATN():
    with StringIO() as buf:
        buf.write(u"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3")
        buf.write(u"\n\35\4\2\t\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2")
        buf.write(u"\3\2\3\2\3\2\3\2\3\2\5\2\24\n\2\3\2\3\2\7\2\30\n\2\f")
        buf.write(u"\2\16\2\33\13\2\3\2\2\3\2\3\2\2\2\37\2\23\3\2\2\2\4\5")
        buf.write(u"\b\2\1\2\5\24\7\3\2\2\6\24\7\4\2\2\7\b\7\5\2\2\b\t\5")
        buf.write(u"\2\2\2\t\n\7\6\2\2\n\13\5\2\2\2\13\f\7\7\2\2\f\24\3\2")
        buf.write(u"\2\2\r\16\7\5\2\2\16\17\5\2\2\2\17\20\7\b\2\2\20\21\5")
        buf.write(u"\2\2\2\21\22\7\7\2\2\22\24\3\2\2\2\23\4\3\2\2\2\23\6")
        buf.write(u"\3\2\2\2\23\7\3\2\2\2\23\r\3\2\2\2\24\31\3\2\2\2\25\26")
        buf.write(u"\f\3\2\2\26\30\7\t\2\2\27\25\3\2\2\2\30\33\3\2\2\2\31")
        buf.write(u"\27\3\2\2\2\31\32\3\2\2\2\32\3\3\2\2\2\33\31\3\2\2\2")
        buf.write(u"\4\23\31")
        return buf.getvalue()


class regexParser ( Parser ):

    grammarFileName = "regex.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ u"<INVALID>", u"'a'", u"'b'", u"'('", u"'+'", u"')'", 
                     u"'.'", u"'*'" ]

    symbolicNames = [ u"<INVALID>", u"<INVALID>", u"<INVALID>", u"<INVALID>", 
                      u"<INVALID>", u"<INVALID>", u"<INVALID>", u"<INVALID>", 
                      u"WS" ]

    RULE_expr = 0

    ruleNames =  [ u"expr" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    WS=8

    def __init__(self, input):
        super(regexParser, self).__init__(input)
        self.checkVersion("4.5.3")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class ExprContext(ParserRuleContext):

        def __init__(self, parser, parent=None, invokingState=-1):
            super(regexParser.ExprContext, self).__init__(parent, invokingState)
            self.parser = parser

        def expr(self, i=None):
            if i is None:
                return self.getTypedRuleContexts(regexParser.ExprContext)
            else:
                return self.getTypedRuleContext(regexParser.ExprContext,i)


        def getRuleIndex(self):
            return regexParser.RULE_expr

        def enterRule(self, listener):
            if hasattr(listener, "enterExpr"):
                listener.enterExpr(self)

        def exitRule(self, listener):
            if hasattr(listener, "exitExpr"):
                listener.exitExpr(self)



    def expr(self, _p=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = regexParser.ExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 0
        self.enterRecursionRule(localctx, 0, self.RULE_expr, _p)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 17
            self._errHandler.sync(self);
            la_ = self._interp.adaptivePredict(self._input,0,self._ctx)
            if la_ == 1:
                self.state = 3
                self.match(regexParser.T__0)
                pass

            elif la_ == 2:
                self.state = 4
                self.match(regexParser.T__1)
                pass

            elif la_ == 3:
                self.state = 5
                self.match(regexParser.T__2)
                self.state = 6
                self.expr(0)
                self.state = 7
                self.match(regexParser.T__3)
                self.state = 8
                self.expr(0)
                self.state = 9
                self.match(regexParser.T__4)
                pass

            elif la_ == 4:
                self.state = 11
                self.match(regexParser.T__2)
                self.state = 12
                self.expr(0)
                self.state = 13
                self.match(regexParser.T__5)
                self.state = 14
                self.expr(0)
                self.state = 15
                self.match(regexParser.T__4)
                pass


            self._ctx.stop = self._input.LT(-1)
            self.state = 23
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,1,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    localctx = regexParser.ExprContext(self, _parentctx, _parentState)
                    self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                    self.state = 19
                    if not self.precpred(self._ctx, 1):
                        from antlr4.error.Errors import FailedPredicateException
                        raise FailedPredicateException(self, "self.precpred(self._ctx, 1)")
                    self.state = 20
                    self.match(regexParser.T__6) 
                self.state = 25
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,1,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx



    def sempred(self, localctx, ruleIndex, predIndex):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[0] = self.expr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def expr_sempred(self, localctx, predIndex):
            if predIndex == 0:
                return self.precpred(self._ctx, 1)
