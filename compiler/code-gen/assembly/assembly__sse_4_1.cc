/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.4.0, DynASM x64 version 1.4.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly__sse_4_1.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
/**
 * Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
 * Distributed under the MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <assembly__sse_4_1.hh>
#include <iostream>
#include <stdio.h>
#include <stdint.h>



//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 28 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 30 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 32 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[266] = {
  85,72,137,229,255,252,243,64,15,126,4,240,140,37,237,255,72,131,252,236,8,
  102,64,15,214,4,240,140,36,255,252,243,64,15,126,192,240,132,240,52,255,252,
  243,64,15,126,133,253,240,140,233,255,102,64,15,214,133,253,240,140,233,255,
  249,255,252,233,245,255,252,242,64,15,194,192,240,132,240,52,235,102,64,15,
  56,23,192,240,133,240,53,255,15,133,245,255,15,132,245,255,248,1,255,248,
  2,255,248,3,255,252,233,244,247,255,252,233,244,248,255,252,233,244,249,255,
  196,225,123,240,160,194,192,240,133,240,45,235,196,226,121,14,192,240,133,
  240,37,255,15,133,244,247,255,15,133,244,248,255,15,133,244,249,255,15,132,
  244,247,255,15,132,244,248,255,15,132,244,249,255,252,242,64,15,88,192,240,
  132,240,52,255,252,242,64,15,92,192,240,132,240,52,255,252,242,64,15,89,192,
  240,132,240,52,255,252,242,64,15,94,192,240,132,240,52,255,72,184,237,237,
  252,255,208,255,252,243,64,15,126,192,240,140,255,252,243,64,15,126,4,240,
  140,36,255,72,131,196,8,255,252,243,64,15,126,192,240,44,255,72,137,252,236,
  93,195,255
};

#line 33 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

Assembly__SSE_4_1::~Assembly__SSE_4_1()
{
    dasm_free(&d);
}

void Assembly__SSE_4_1::initialize(int parameterCount) {
    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;

    stackPos = parameterCount >= 8 ? 7 : parameterCount-1;
}

void Assembly__SSE_4_1::prologue(){
    //| push rbp
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 63 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;
    double* ptr = static_cast<double*>(malloc(sizeof(double)));
    *ptr = value;
    //| movq xmm(stackPos), qword[ptr]
    dasm_put(Dst, 5, (stackPos), ptr);
#line 75 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::storeLocalVariable() {
    //| sub rsp, 8
    //| movq qword [rsp], xmm(stackPos)
    dasm_put(Dst, 16, (stackPos));
#line 80 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(stackPos), xmm(index)
        dasm_put(Dst, 30, (stackPos), (index));
#line 88 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
        dasm_put(Dst, 41, (stackPos), 8+(index-7)*8);
#line 91 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

void Assembly__SSE_4_1::popStack(){
    stackPos--;
}

void Assembly__SSE_4_1::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(index), xmm(stackPos)
        dasm_put(Dst, 30, (index), (stackPos));
#line 102 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
        dasm_put(Dst, 52, (stackPos), 8+(index-7)*8);
#line 105 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

void Assembly__SSE_4_1::pushLocalVariableToStack(int index) {
    stackPos++;
    //| movq xmm(stackPos), qword [rbp-8-index*8]
    dasm_put(Dst, 41, (stackPos), -8-index*8);
#line 112 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::replaceLocalVariable(int index) {
    //| movq qword [rbp-8-index*8], xmm(stackPos)
    dasm_put(Dst, 52, (stackPos), -8-index*8);
#line 116 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 62, labelNumber);
#line 121 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 64, labelNumber);
#line 125 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
     //| ptest xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 68, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 131 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 90,  labelNumber);
#line 133 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 94,  labelNumber);
#line 136 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     stackPos--;
}

void Assembly__SSE_4_1::addLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| 1:
            dasm_put(Dst, 98);
#line 144 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
            }
        case 2: {
            //| 2:
            dasm_put(Dst, 101);
#line 148 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
        case 3: {
            //| 3:
            dasm_put(Dst, 104);
#line 152 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
    }
}

void Assembly__SSE_4_1::jumpForwardToLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| jmp >1
            dasm_put(Dst, 107);
#line 161 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
            }
        case 2: {
            //| jmp >2
            dasm_put(Dst, 112);
#line 165 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
        case 3: {
            //| jmp >3
            dasm_put(Dst, 117);
#line 169 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
    }
}

void Assembly__SSE_4_1::conditionalJumpForwardToLocalLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| vcmpsd xmm(stackPos), xmm(stackPos), xmm(stackPos-1), operator_
     //| vptestps xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 122, (stackPos), (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 177 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
        switch(labelNumber){
            case 1: {
                //| jnz >1
                dasm_put(Dst, 144);
#line 181 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 2: {
                //| jnz >2
                dasm_put(Dst, 149);
#line 185 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 3: {
                //| jnz >3
                dasm_put(Dst, 154);
#line 189 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
        }
     }
     else{
        switch(labelNumber){
            case 1: {
                //| jz >1
                dasm_put(Dst, 159);
#line 197 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 2: {
                //| jz >2
                dasm_put(Dst, 164);
#line 201 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 3: {
                //| jz >3
                dasm_put(Dst, 169);
#line 205 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
        }
     }
     stackPos--;
}

void Assembly__SSE_4_1::calculateAddition(){
    //| addsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 174, (stackPos-1), (stackPos));
#line 214 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateSubtraction(){
    //| subsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 185, (stackPos-1), (stackPos));
#line 219 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateMultiplication(){
    //| mulsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 196, (stackPos-1), (stackPos));
#line 224 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateDivision(){
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 207, (stackPos-1), (stackPos));
#line 229 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup registers which will be filled with parameters
    for(int i=0; i<numberOfArguments; i++){
       //| sub rsp, 8
       //| movq qword [rsp], xmm(i)
       dasm_put(Dst, 16, (i));
#line 238 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

    //Load parameters to register
    for(int i=stackPos-(numberOfArguments-1); i<=stackPos; i++){
       //| movq xmm(i-(stackPos-(numberOfArguments-1))), xmm(i)
       dasm_put(Dst, 30, (i-(stackPos-(numberOfArguments-1))), (i));
#line 243 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    stackPos = stackPos-(numberOfArguments-1);

    //Perform function Call
    //| mov64 rax, (uintptr_t) functionPtr
    //| call rax
    dasm_put(Dst, 218, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 252 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    //Put function result on top of stack
    //| movq xmm(stackPos), xmm0
    dasm_put(Dst, 226, (stackPos));
#line 255 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    //Restore registers
     for(int i=numberOfArguments-1; i>=0; i--){
        if(i < stackPos){
            //| movq xmm(i), qword [rsp]
            dasm_put(Dst, 235, (i));
#line 260 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        //| add rsp, 8
        dasm_put(Dst, 245);
#line 262 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
}

void Assembly__SSE_4_1::extractResult(){
     //| movq xmm0, xmm(stackPos)
     dasm_put(Dst, 250, (stackPos));
#line 267 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::epilogue(){
    //| mov rsp, rbp
    //| pop rbp
    //| ret
    dasm_put(Dst, 259);
#line 274 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

dasm_gen_func Assembly__SSE_4_1::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}

