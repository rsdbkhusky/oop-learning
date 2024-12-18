//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_OUTPUTPROCESSOR_H
#define FINAL_OUTPUTPROCESSOR_H

#include <algorithm>
#include "../UI/IUI.h"
#include "../UI/UI.h"
#include "../UI/UIText.h"
#include "../UI/UIButton.h"
#include "../UI/UISudoku.h"
#include "../UI/UContainer.h"
#include "../UI/UContainerHorizontal.h"
#include "../UI/UContainerVertical.h"
#include "../Logic/LogicCell.h"
#include "../Logic/LogicSudoku.h"
using std::max;

class OutputProcessor {
public:
    static void initvcc(vector<vector<char>>& vcc, int n, int m) {
        vcc.resize(n);
        for (int i = 0; i < n; ++i) {
            vcc[i].resize(m);
            fill(vcc[i].begin(), vcc[i].end(), ' ');
        }
    }
    static vector<vector<char>> iui2vvc(const IUI& iui) {
        vector<vector<char>> result;
        int n = 0, m = 0;
        if (dynamic_cast<const UI*>(&iui) != nullptr) {
            if (dynamic_cast<const UIText*>(&iui) != nullptr) {
                const string& text = dynamic_cast<const UIText&>(iui).getText();
                initvcc(result, n = 1, m = int(text.size()));
                for (int i = 0; i < text.size(); ++i) result[0][i] = text[i];
            } else if (dynamic_cast<const UIButton*>(&iui) != nullptr) {
                const vector<vector<char>>& text = dynamic_cast<const UIButton&>(iui).getText();
                for (int i = 0; i < text.size(); ++i) m = max(m, (int)text[i].size());
                initvcc(result, n = text.size() + 2, m = m + 4);
                for (int i = 0; i < n; ++i) result[i][0] = result[i][m - 1] = '*';
                for (int i = 0; i < m; ++i) result[0][i] = result[n - 1][i] = '*';
                for (int i = 0; i < text.size(); ++i) {
                    for (int j = 0; j < text[i].size(); ++j) {
                        result[1 + i][(m - text[i].size()) / 2 + j] = text[i][j];
                    }
                }
            } else if (dynamic_cast<const UISudoku*>(&iui) != nullptr) {
                const LogicSudoku& ls = dynamic_cast<const UISudoku&>(iui).getLogicSudoku();
                int lencell = ls.getLenCell();
                initvcc(result, 3 + (n = 1 + (lencell + 1) * lencell * lencell), 3 + (m = 1 + (lencell + 1) * lencell * lencell));
                for (int i = 0; i < n; i += lencell + 1) {
                    for (int j = 0; j < m; ++j) {
                        result[i + 3][j + 3] = result[j + 3][i + 3] = '*';
                    }
                }
                for (int i = 0; i < n; i += (lencell + 1) * lencell) {
                    for (int j = 0; j < m; ++j) {
                        result[i + 3][j + 3] = result[j + 3][i + 3] = '#';
                    }
                }
                const vector<vector<LogicCell*>>& cells = ls.getCells();
                for (int i = 0, x = 1; i < lencell * lencell; ++i, x += lencell + 1) {
                    for (int j = 0, y = 1; j < lencell * lencell; ++j, y += lencell + 1) {
                        if (cells[i][j]->getStatus() == LogicCellStatus::PENDING) {
                            for (const auto& num: cells[i][j]->getCandidates()) {
                                char ch = num < 10 ? num + '0' : num - 10 + 'A';
                                result[x + (num - 1) / lencell + 3][y + (num - 1) % lencell + 3] = ch;
                            }
                        } else if (cells[i][j]->getStatus() == LogicCellStatus::CONFIRMED) {
                            int num = cells[i][j]->getNum();
                            char ch = num < 10 ? num + '0' : num - 10 + 'A';
                            result[x + (lencell - 1) / 2 + 3][y + (lencell - 1) / 2 + 3] = ch;
                        }
                    }
                }
                for (int i = 0, x = lencell + 2; i < lencell * lencell; ++i, x += lencell + 1) {
                    result[x][0] = 'R';
                    result[x][1] = (i + 1) + '0';
                }
                for (int j = 0, y = lencell + 2; j < lencell * lencell; ++j, y += lencell + 1) {
                    result[0][y] = 'C';
                    result[1][y] = (j + 1) + '0';
                }
            }
        } else if (dynamic_cast<const UContainer*>(&iui) != nullptr) {
            if (dynamic_cast<const UContainerHorizontal*>(&iui) != nullptr) {
                const vector<IUI*>& soniuis = dynamic_cast<const UContainerHorizontal&>(iui).getIUIs();
                vector<vector<vector<char>>> vvvc;
                m = soniuis.size() - 1;
                for (auto& soniui: soniuis) {
                    vvvc.push_back(iui2vvc(*soniui));
                    n = max(n, (int)vvvc.back().size());
                    m += vvvc.back()[0].size();
                }
                initvcc(result, n, m);
                int yy = 0;
                for (auto& vvc: vvvc) {
                    for (int i = 0, x = (n - (int)vvc.size()) / 2; i < vvc.size(); ++i, ++x) {
                        for (int j = 0, y = yy; j < vvc[0].size(); ++j, ++y) {
                            result[x][y] = vvc[i][j];
                        }
                    }
                    yy += vvc[0].size() + 1;
                }
            } else if (dynamic_cast<const UContainerVertical*>(&iui) != nullptr) {
                const vector<IUI*>& soniuis = dynamic_cast<const UContainerVertical&>(iui).getIUIs();
                vector<vector<vector<char>>> vvvc;
                n = soniuis.size() - 1;
                for (auto& soniui: soniuis) {
                    vvvc.push_back(iui2vvc(*soniui));
                    m = max(m, (int)vvvc.back()[0].size());
                    n += vvvc.back().size();
                }
                initvcc(result, n, m);
                int xx = 0;
                for (auto& vvc: vvvc) {
                    for (int i = 0, x = xx; i < vvc.size(); ++i, ++x) {
                        for (int j = 0, y = (m - (int)vvc[0].size()) / 2; j < vvc[0].size(); ++j, ++y) {
                            result[x][y] = vvc[i][j];
                        }
                    }
                    xx += vvc.size() + 1;
                }
            }
        }
        return result;
    }
};


#endif //FINAL_OUTPUTPROCESSOR_H
