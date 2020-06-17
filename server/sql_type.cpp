﻿/*
	Copyright (c) 2017 TOSHIBA Digital Solutions Corporation

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "sql_type.h"
#include <cassert>

const util::NameCoderEntry<SQLType::Id> SQLType::Coder::ID_LIST[] = {
	UTIL_NAME_CODER_NON_NAME_ENTRY(START_EXEC),
	UTIL_NAME_CODER_ENTRY(EXEC_REFERENCE),
	UTIL_NAME_CODER_ENTRY(EXEC_GROUP),
	UTIL_NAME_CODER_ENTRY(EXEC_JOIN),
	UTIL_NAME_CODER_ENTRY(EXEC_LIMIT),
	UTIL_NAME_CODER_ENTRY(EXEC_SCAN),
	UTIL_NAME_CODER_ENTRY(EXEC_SELECT),
	UTIL_NAME_CODER_ENTRY(EXEC_SORT),
	UTIL_NAME_CODER_ENTRY(EXEC_UNION),
	UTIL_NAME_CODER_ENTRY(EXEC_DELETE),
	UTIL_NAME_CODER_ENTRY(EXEC_INSERT),
	UTIL_NAME_CODER_ENTRY(EXEC_UPDATE),
	UTIL_NAME_CODER_ENTRY(EXEC_DDL),
	UTIL_NAME_CODER_ENTRY(EXEC_RESULT),
	UTIL_NAME_CODER_NON_NAME_ENTRY(END_EXEC),

	UTIL_NAME_CODER_NON_NAME_ENTRY(START_EXPR),
	UTIL_NAME_CODER_ENTRY(EXPR_ID),
	UTIL_NAME_CODER_ENTRY(EXPR_TABLE),
	UTIL_NAME_CODER_ENTRY(EXPR_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_CONSTANT),
	UTIL_NAME_CODER_ENTRY(EXPR_TYPE),
	UTIL_NAME_CODER_ENTRY(EXPR_SELECTION),
	UTIL_NAME_CODER_ENTRY(EXPR_PRODUCTION),
	UTIL_NAME_CODER_ENTRY(EXPR_PROJECTION),
	UTIL_NAME_CODER_ENTRY(EXPR_JOIN),
	UTIL_NAME_CODER_ENTRY(EXPR_AND),
	UTIL_NAME_CODER_ENTRY(EXPR_OR),
	UTIL_NAME_CODER_ENTRY(EXPR_BETWEEN),
	UTIL_NAME_CODER_ENTRY(EXPR_CASE),
	UTIL_NAME_CODER_ENTRY(EXPR_IN),
	UTIL_NAME_CODER_ENTRY(EXPR_EXISTS),
	UTIL_NAME_CODER_ENTRY(EXPR_ALL_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_FUNCTION),
	UTIL_NAME_CODER_ENTRY(EXPR_PLACEHOLDER),
	UTIL_NAME_CODER_ENTRY(EXPR_LIMITED_PROJECTION),
	UTIL_NAME_CODER_ENTRY(EXPR_SUB_LIMITED_PROJECTION),
	UTIL_NAME_CODER_ENTRY(EXPR_LIST),
	UTIL_NAME_CODER_ENTRY(EXPR_AGG_LIST),
	UTIL_NAME_CODER_ENTRY(EXPR_WINDOW_COLUMN_LIST),
	UTIL_NAME_CODER_ENTRY(EXPR_AGG_FOLLOWING),
	UTIL_NAME_CODER_ENTRY(EXPR_COND),
	UTIL_NAME_CODER_ENTRY(EXPR_SCAN),
	UTIL_NAME_CODER_ENTRY(EXPR_TUPLE_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_CONTAINER_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_COLLECTION_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_TIME_SERIES_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_META_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_VIRTUAL_COLUMN),
	UTIL_NAME_CODER_ENTRY(EXPR_FILTER_ID),
	UTIL_NAME_CODER_ENTRY(EXPR_FILTER_ORDERED_ID),
	UTIL_NAME_CODER_ENTRY(EXPR_HINT_NO_INDEX),
	UTIL_NAME_CODER_NON_NAME_ENTRY(END_EXPR),

	UTIL_NAME_CODER_NON_NAME_ENTRY(START_AGG),
	UTIL_NAME_CODER_ENTRY(AGG_AVG),
	UTIL_NAME_CODER_ENTRY(AGG_COUNT_ALL),
	UTIL_NAME_CODER_ENTRY(AGG_COUNT_COLUMN),
	UTIL_NAME_CODER_ENTRY(AGG_GROUP_CONCAT),
	UTIL_NAME_CODER_ENTRY(AGG_LAG),
	UTIL_NAME_CODER_ENTRY(AGG_LEAD),
	UTIL_NAME_CODER_ENTRY(AGG_MAX),
	UTIL_NAME_CODER_ENTRY(AGG_MEDIAN),
	UTIL_NAME_CODER_ENTRY(AGG_MIN),
	UTIL_NAME_CODER_ENTRY(AGG_ROW_NUMBER),
	UTIL_NAME_CODER_ENTRY(AGG_STDDEV),
	UTIL_NAME_CODER_ENTRY(AGG_STDDEV0),
	UTIL_NAME_CODER_ENTRY(AGG_STDDEV_POP),
	UTIL_NAME_CODER_ENTRY(AGG_STDDEV_SAMP),
	UTIL_NAME_CODER_ENTRY(AGG_SUM),
	UTIL_NAME_CODER_ENTRY(AGG_TOTAL),
	UTIL_NAME_CODER_ENTRY(AGG_VAR_POP),
	UTIL_NAME_CODER_ENTRY(AGG_VAR_SAMP),
	UTIL_NAME_CODER_ENTRY(AGG_VARIANCE),
	UTIL_NAME_CODER_ENTRY(AGG_VARIANCE0),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_AVG),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_COUNT_COLUMN),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_GROUP_CONCAT),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_STDDEV),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_STDDEV0),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_STDDEV_POP),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_STDDEV_SAMP),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_SUM),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_TOTAL),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_VAR_POP),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_VAR_SAMP),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_VARIANCE),
	UTIL_NAME_CODER_ENTRY(AGG_DISTINCT_VARIANCE0),
	UTIL_NAME_CODER_ENTRY(AGG_FIRST),
	UTIL_NAME_CODER_ENTRY(AGG_LAST),
	UTIL_NAME_CODER_ENTRY(AGG_FOLD_EXISTS),
	UTIL_NAME_CODER_ENTRY(AGG_FOLD_NOT_EXISTS),
	UTIL_NAME_CODER_ENTRY(AGG_FOLD_IN),
	UTIL_NAME_CODER_ENTRY(AGG_FOLD_NOT_IN),
	UTIL_NAME_CODER_ENTRY(AGG_FOLD_UPTO_ONE),
	UTIL_NAME_CODER_NON_NAME_ENTRY(END_AGG),

	UTIL_NAME_CODER_NON_NAME_ENTRY(START_FUNC),
	UTIL_NAME_CODER_ENTRY(FUNC_ABS),
	UTIL_NAME_CODER_ENTRY(FUNC_CHAR),
	UTIL_NAME_CODER_ENTRY(FUNC_COALESCE),
	UTIL_NAME_CODER_ENTRY(FUNC_GLOB),
	UTIL_NAME_CODER_ENTRY(FUNC_IFNULL),
	UTIL_NAME_CODER_ENTRY(FUNC_INSTR),
	UTIL_NAME_CODER_ENTRY(FUNC_HEX),
	UTIL_NAME_CODER_ENTRY(FUNC_HEX_TO_DEC),
	UTIL_NAME_CODER_ENTRY(FUNC_LENGTH),
	UTIL_NAME_CODER_ENTRY(FUNC_LIKE),
	UTIL_NAME_CODER_ENTRY(FUNC_LOG),
	UTIL_NAME_CODER_ENTRY(FUNC_LOWER),
	UTIL_NAME_CODER_ENTRY(FUNC_LTRIM),
	UTIL_NAME_CODER_ENTRY(FUNC_MAX),
	UTIL_NAME_CODER_ENTRY(FUNC_MIN),
	UTIL_NAME_CODER_ENTRY(FUNC_NULLIF),
	UTIL_NAME_CODER_ENTRY(FUNC_PRINTF),
	UTIL_NAME_CODER_ENTRY(FUNC_QUOTE),
	UTIL_NAME_CODER_ENTRY(FUNC_RANDOM),
	UTIL_NAME_CODER_ENTRY(FUNC_RANDOMBLOB),
	UTIL_NAME_CODER_ENTRY(FUNC_REPLACE),
	UTIL_NAME_CODER_ENTRY(FUNC_ROUND),
	UTIL_NAME_CODER_ENTRY(FUNC_RTRIM),
	UTIL_NAME_CODER_ENTRY(FUNC_SQRT),
	UTIL_NAME_CODER_ENTRY(FUNC_SUBSTR),
	UTIL_NAME_CODER_ENTRY(FUNC_SUBSTR_WITH_BOUNDS),
	UTIL_NAME_CODER_ENTRY(FUNC_TRANSLATE),
	UTIL_NAME_CODER_ENTRY(FUNC_TRIM),
	UTIL_NAME_CODER_ENTRY(FUNC_TRUNC),
	UTIL_NAME_CODER_ENTRY(FUNC_TYPEOF),
	UTIL_NAME_CODER_ENTRY(FUNC_UNICODE),
	UTIL_NAME_CODER_ENTRY(FUNC_UPPER),
	UTIL_NAME_CODER_ENTRY(FUNC_ZEROBLOB),

	UTIL_NAME_CODER_ENTRY(FUNC_EXTRACT),
	UTIL_NAME_CODER_ENTRY(FUNC_MAKE_TIMESTAMP),
	UTIL_NAME_CODER_ENTRY(FUNC_MAKE_TIMESTAMP_BY_DATE),
	UTIL_NAME_CODER_ENTRY(FUNC_NOW),
	UTIL_NAME_CODER_ENTRY(FUNC_STRFTIME),
	UTIL_NAME_CODER_ENTRY(FUNC_TO_EPOCH_MS),
	UTIL_NAME_CODER_ENTRY(FUNC_TO_TIMESTAMP_MS),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMP),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMP_TRUNC),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMP_ADD),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMP_DIFF),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMPADD),
	UTIL_NAME_CODER_ENTRY(FUNC_TIMESTAMPDIFF),
	UTIL_NAME_CODER_NON_NAME_ENTRY(END_FUNC),

	UTIL_NAME_CODER_NON_NAME_ENTRY(START_OP),
	UTIL_NAME_CODER_ENTRY(OP_CONCAT),
	UTIL_NAME_CODER_ENTRY(OP_MULTIPLY),
	UTIL_NAME_CODER_ENTRY(OP_DIVIDE),
	UTIL_NAME_CODER_ENTRY(OP_REMAINDER),
	UTIL_NAME_CODER_ENTRY(OP_ADD),
	UTIL_NAME_CODER_ENTRY(OP_SUBTRACT),
	UTIL_NAME_CODER_ENTRY(OP_SHIFT_LEFT),
	UTIL_NAME_CODER_ENTRY(OP_SHIFT_RIGHT),
	UTIL_NAME_CODER_ENTRY(OP_BIT_AND),
	UTIL_NAME_CODER_ENTRY(OP_BIT_OR),
	UTIL_NAME_CODER_ENTRY(OP_LT),
	UTIL_NAME_CODER_ENTRY(OP_LE),
	UTIL_NAME_CODER_ENTRY(OP_GT),
	UTIL_NAME_CODER_ENTRY(OP_GE),
	UTIL_NAME_CODER_ENTRY(OP_EQ),
	UTIL_NAME_CODER_ENTRY(OP_NE),
	UTIL_NAME_CODER_ENTRY(OP_IS),
	UTIL_NAME_CODER_ENTRY(OP_IS_NOT),
	UTIL_NAME_CODER_ENTRY(OP_CAST),
	UTIL_NAME_CODER_ENTRY(OP_IS_NULL),
	UTIL_NAME_CODER_ENTRY(OP_IS_NOT_NULL),
	UTIL_NAME_CODER_ENTRY(OP_BIT_NOT),
	UTIL_NAME_CODER_ENTRY(OP_NOT),
	UTIL_NAME_CODER_ENTRY(OP_PLUS),
	UTIL_NAME_CODER_ENTRY(OP_MINUS),
	UTIL_NAME_CODER_NON_NAME_ENTRY(END_OP)
};

const util::NameCoderEntry<
		SQLType::JoinType> SQLType::Coder::JOIN_TYPE_LIST[] = {
	UTIL_NAME_CODER_ENTRY(JOIN_INNER),
	UTIL_NAME_CODER_ENTRY(JOIN_LEFT_OUTER),
	UTIL_NAME_CODER_ENTRY(JOIN_RIGHT_OUTER),
	UTIL_NAME_CODER_ENTRY(JOIN_FULL_OUTER),
	UTIL_NAME_CODER_ENTRY(JOIN_NATURAL_INNER),
	UTIL_NAME_CODER_ENTRY(JOIN_NATURAL_LEFT_OUTER),
	UTIL_NAME_CODER_ENTRY(JOIN_NATURAL_RIGHT_OUTER),
	UTIL_NAME_CODER_ENTRY(JOIN_NATURAL_FULL_OUTER)
};

const util::NameCoderEntry<
		SQLType::OrderDirection> SQLType::Coder::DIRECTION_LIST[] = {
	UTIL_NAME_CODER_ENTRY(DIRECTION_ASC),
	UTIL_NAME_CODER_ENTRY(DIRECTION_DESC)
};

const util::NameCoderEntry<
		SQLType::UnionType> SQLType::Coder::UNION_TYPE_LIST[] = {
	UTIL_NAME_CODER_ENTRY(UNION_ALL),
	UTIL_NAME_CODER_ENTRY(UNION_DISTINCT),
	UTIL_NAME_CODER_ENTRY(UNION_INTERSECT),
	UTIL_NAME_CODER_ENTRY(UNION_EXCEPT)
};

const util::NameCoderEntry<
		SQLType::AggregationPhase> SQLType::Coder::AGG_PHASE_LIST[] = {
	UTIL_NAME_CODER_ENTRY_CUSTOM("ALL", AGG_PHASE_ALL_PIPE),
	UTIL_NAME_CODER_ENTRY_CUSTOM("MERGE", AGG_PHASE_MERGE_PIPE),
	UTIL_NAME_CODER_ENTRY_CUSTOM("ADVANCE", AGG_PHASE_ADVANCE_PIPE),

	UTIL_NAME_CODER_ENTRY_CUSTOM("MERGE_FINISH", AGG_PHASE_MERGE_FINISH),
	UTIL_NAME_CODER_ENTRY_CUSTOM("ADVANCE_FINISH", AGG_PHASE_ADVANCE_FINISH)
};

const util::NameCoderEntry<
		SQLType::TableType> SQLType::Coder::TABLE_TYPE_LIST[] = {
	UTIL_NAME_CODER_ENTRY(TABLE_CONTAINER),
	UTIL_NAME_CODER_ENTRY(TABLE_META)
};

const util::NameCoderEntry<
		SQLType::IndexType> SQLType::Coder::INDEX_TYPE_LIST[] = {
	UTIL_NAME_CODER_ENTRY(INDEX_TREE_RANGE),
	UTIL_NAME_CODER_ENTRY(INDEX_TREE_EQ),
	UTIL_NAME_CODER_ENTRY(INDEX_HASH)
};

const util::NameCoder<SQLType::Id, SQLType::END_TYPE>
		SQLType::Coder::ID_CODER(ID_LIST, 0);

const util::NameCoder<SQLType::Id, SQLType::END_EXEC>
		SQLType::Coder::EXEC_ID_CODER = makeExecIdCoder(ID_LIST);

const util::NameCoder<SQLType::JoinType, SQLType::END_JOIN>
		SQLType::Coder::JOIN_TYPE_CODER(JOIN_TYPE_LIST, 1);

const util::NameCoder<SQLType::OrderDirection, SQLType::END_DIRECTION>
		SQLType::Coder::DIRECTION_CODER(DIRECTION_LIST, 1);

const util::NameCoder<SQLType::UnionType, SQLType::END_UNION>
		SQLType::Coder::UNION_TYPE_CODER(UNION_TYPE_LIST, 1);

const util::NameCoder<SQLType::AggregationPhase, SQLType::END_AGG_PHASE>
		SQLType::Coder::AGG_PHASE_CODER(AGG_PHASE_LIST, 0);

const util::NameCoder<SQLType::TableType, SQLType::END_TABLE>
		SQLType::Coder::TABLE_TYPE_CODER(TABLE_TYPE_LIST, 1);

const util::NameCoder<SQLType::IndexType, SQLType::END_INDEX>
		SQLType::Coder::INDEX_TYPE_CODER(INDEX_TYPE_LIST, 1);

const char8_t* SQLType::Coder::operator()(Id id, const char8_t *name) const {
	const char8_t *execName = EXEC_ID_CODER(id, NULL);
	if (execName != NULL) {
		return execName;
	}

	return ID_CODER(id, name);
}

bool SQLType::Coder::operator()(const char8_t *name, Id &id) const {
	if (EXEC_ID_CODER(name, id)) {
		return true;
	}

	return ID_CODER(name, id);
}

const char8_t* SQLType::Coder::operator()(
		JoinType type, const char8_t *name) const {
	return JOIN_TYPE_CODER(type, name);
}

bool SQLType::Coder::operator()(const char8_t *name, JoinType &type) const {
	return JOIN_TYPE_CODER(name, type);
}

const char8_t* SQLType::Coder::operator()(
		OrderDirection direction, const char8_t *name) const {
	return DIRECTION_CODER(direction, name);
}

bool SQLType::Coder::operator()(
		const char8_t *name, OrderDirection &direction) const {
	return DIRECTION_CODER(name, direction);
}

const char8_t* SQLType::Coder::operator()(
		UnionType type, const char8_t *name) const {
	return UNION_TYPE_CODER(type, name);
}

bool SQLType::Coder::operator()(const char8_t *name, UnionType &type) const {
	return UNION_TYPE_CODER(name, type);
}

const char8_t* SQLType::Coder::operator()(
		AggregationPhase phase, const char8_t *name) const {
	return AGG_PHASE_CODER(phase, name);
}

bool SQLType::Coder::operator()(
		const char8_t *name, AggregationPhase &phase) const {
	return AGG_PHASE_CODER(name, phase);
}

const char8_t* SQLType::Coder::operator()(
		TableType type, const char8_t *name) const {
	return TABLE_TYPE_CODER(type, name);
}

bool SQLType::Coder::operator()(const char8_t *name, TableType &type) const {
	return TABLE_TYPE_CODER(name, type);
}

const char8_t* SQLType::Coder::operator()(
		IndexType type, const char8_t *name) const {
	return INDEX_TYPE_CODER(type, name);
}

bool SQLType::Coder::operator()(const char8_t *name, IndexType &type) const {
	return INDEX_TYPE_CODER(name, type);
}

util::NameCoder<SQLType::Id, SQLType::END_EXEC>
SQLType::Coder::makeExecIdCoder(
		const util::NameCoderEntry<Id> (&idList)[END_TYPE]) {
	static util::NameCoderEntry<Id> execList[END_EXEC];
	UTIL_STATIC_ASSERT(0 < END_EXEC && END_EXEC < END_TYPE);

	util::NameCoderEntry<Id> *destIt = execList;

	const util::NameCoderEntry<Id> *srcIt = idList;
	const util::NameCoderEntry<Id> *const srcEnd = srcIt + END_EXEC;
	for (; srcIt != srcEnd; ++srcIt, ++destIt) {
		*destIt = *srcIt;
	}

	return util::NameCoder<Id, END_EXEC>(execList, 1);
}

bool SQLType::isNatural(JoinType type) {
	switch (type) {
	case JOIN_INNER:
	case JOIN_LEFT_OUTER:
	case JOIN_RIGHT_OUTER:
	case JOIN_FULL_OUTER:
		return false;
	case JOIN_NATURAL_INNER:
	case JOIN_NATURAL_LEFT_OUTER:
	case JOIN_NATURAL_RIGHT_OUTER:
	case JOIN_NATURAL_FULL_OUTER:
		return true;
	default:
		assert(false);
		return false;
	}
}

SQLType::JoinType SQLType::removeNatural(JoinType type) {
	switch (type) {
	case JOIN_INNER:
	case JOIN_LEFT_OUTER:
	case JOIN_RIGHT_OUTER:
	case JOIN_FULL_OUTER:
		return type;
	case JOIN_NATURAL_INNER:
		return JOIN_INNER;
	case JOIN_NATURAL_LEFT_OUTER:
		return JOIN_LEFT_OUTER;
	case JOIN_NATURAL_RIGHT_OUTER:
		return JOIN_RIGHT_OUTER;
	case JOIN_NATURAL_FULL_OUTER:
		return JOIN_FULL_OUTER;
	default:
		assert(false);
		return type;
	}
}
