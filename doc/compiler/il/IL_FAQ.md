<!--
Copyright (c) 2000, 2017 IBM Corp. and others

This program and the accompanying materials are made available under
the terms of the Eclipse Public License 2.0 which accompanies this
distribution and is available at https://www.eclipse.org/legal/epl-2.0/
or the Apache License, Version 2.0 which accompanies this distribution and
is available at https://www.apache.org/licenses/LICENSE-2.0.

This Source Code may also be made available under the following
Secondary Licenses when the conditions for such availability set
forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
General Public License, version 2 with the GNU Classpath
Exception [1] and GNU General Public License, version 2 with the
OpenJDK Assembly Exception [2].

[1] https://www.gnu.org/software/classpath/license.html
[2] http://openjdk.java.net/legal/assembly-exception.html

SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
-->

# IL FAQ 

This document captures some commonly asked, or important subtleties about the TR IL. 

This may be also consided in tandem with its sister document, [the J9 IL FAQ][faq], 
which documents pieces that are specific to the J9 project's use of the TR IL. 

[faq]: https://github.com/eclipse/openj9/blob/master/doc/compiler/IL_FAQ.md

## Why 'Trees', if the actual structure is a DAG?

(_Captured from [this github comment by @ymanton][ymanton]_)

> It's a doubly-linked list of polytrees prior to optimization, and polytrees
> are specific kind of DAG. It's the act of commoning that introduces links and
> causes two or more polytrees to stop being polytrees, at which point it's
> just a DAG. After optimization you end up with a linked list of polytrees,
> DAGS, or both. Having said that the name is probably simply colloquial rather
> than strictly accurate w.r.t. graph theory.

## When does a node need to exist under a treetop node?

(_Captured from [this github comment by @ymanton][ymanton]_)

> Most nodes exist under a root node, only a few certain node types are
> qualified to be roots, or "treetops" if you will, but most are not.
> 
> Usually it's the nodes that have side effects, that need to be evaluated at
> exactly that point, that are treetops, and everything else can appear as a
> child. The idea is that even though the root nodes need to stay fixed in
> their place relative to other roots, child nodes can be evaluated anywhere;
> if you optimize away a certain root node the evaluation of the children is
> naturally pushed down/pulled up to where it is needed.
> 
> You can think of it in terms of sources and sinks if you want, where root
> nodes are sinks and everything else is a source, except that root nodes can
> themselves produce a result (e.g. calls returning values) and can be sources
> so it's not a perfect comparison.
>
> Anyhow, in practice, it turns out that (depending on the language) you don't
> really have that much freedom of movement, and if you optimize away a root
> you may need to make sure that the children are still evaluated at that
> point, hence the treetop node and IL op (which really should have been named
> "anchor" or something to avoid the eternal confusion it causes with the
> actual TreeTop type), which doesn't evaluate to any machine instruction and
> who's purpose is simply to make sure the children stay where they are and are
> evaluated at that point even though the operation that was consuming them is
> no longer needed.

## Why is there bu2i but no iu2b?

(_Captured from [this github comment by @ymanton][ymanton]_)

> `iu2b` is the same is `i2b`, as truncating to a byte doesn't care about the
> sign, where widening needs to specify one of sign extension or zero
> extension.

[ymanton]: https://github.com/eclipse/omr/issues/1945#issuecomment-342215042
